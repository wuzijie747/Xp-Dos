#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <ctime>
#pragma warning(disable:4996)
#pragma warning(disable:6385)
using namespace std;
int shutdown2 = 0;
int End_process_name = 0;
string PATH;
bool
CheckFolderExist(const string& strPath)
{
	WIN32_FIND_DATA wfd;
	bool rValue = false;
	HANDLE hFind = FindFirstFile(strPath.c_str(), &wfd);
	if ((hFind != INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		rValue = true;
	}
	FindClose(hFind);
	return rValue;
}
int KillProcess(char* szImageName, int fp) {
	PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) }; //获得进程列表
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//拍摄快照
	BOOL bRet = Process32First(hProcess, &pe);//检索快照中第一个进程信息
	while (bRet) {//判断不是最后一个进程，历遍所有
		if (lstrcmp(szImageName, pe.szExeFile) == 0) {//判断是不是要结束的进程
			TerminateProcess(OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID), 0);//打开进程并杀死
			End_process_name = 1;
		}
		bRet = Process32Next(hProcess, &pe);//下一个进程
	}
	if (End_process_name == 0)
	{
		cout << "Process not found\n";
		fp = 0;
	}
	else
	{
		fp = 1;
	}
	return fp;
}
bool Judgment_permissions(string a)
{
	bool f = CheckFolderExist(a);
	bool e = true;
	string b;
	if (f = false)
	{
		e = false;
	}
	else
	{

		if (a.length() == '\\')
		{
			cout << "The end of the directory cannot be a \"\\\" symbol\n";
			e = false;
		}
		else
		{
			b = a + "\\Test_data.txt";
		}

		ofstream Judgment;
		Judgment.open(b.c_str(), ios::out);
		Judgment.close();
		ifstream Judgment2;
		Judgment2.open(b.c_str(), ios::out);
		if (!Judgment2.is_open())
		{
			e = false;
		}
	}
	return e;
}
int main()
{

	system("title Xp-Dos");
	string a12345 = _pgmptr;
	int n6 = a12345.size();
	char* a2456 = new char[n6]();
	strcpy(a2456, a12345.c_str());
	int n = a12345.length() - 1;
	int i = 0;
	for (i = n;; i--)
	{
		if (a12345[i] == '\\')
		{
			break;
		}
	}
	int n2 = i;
	char* f10 = new char[n2]();
	for (int j = 0; j < i; j++)
	{
		f10[j] = a2456[j];
	}
	PATH = f10;
	ifstream OPen;
	ifstream Open_Data_Object_2;
	string PATH_BCP = PATH + "\\Installation.txt";
	Open_Data_Object_2.open(PATH_BCP.c_str(), ios::in);
	if (!Open_Data_Object_2.is_open())
	{
		Open_Data_Object_2.close();
		ofstream Write_Data_Object_2;
		Write_Data_Object_2.open(PATH_BCP.c_str(), ios::out);
		Write_Data_Object_2.close();
		ofstream Write_Data_Object_3;
		Write_Data_Object_3.open(PATH_BCP.c_str(), ios::out);
		string c = "1";
		Write_Data_Object_3 << c;
		Write_Data_Object_3.close();
		system("cls");
		cout << "Welcome to Xp-Dos, let's start with the basics\n";
		cout << "What is your name?\n";
		string User_name_for_input;
		getline(cin, User_name_for_input);
		ofstream Write_Data_Object_4;
		string PATH_NAME = PATH + "\\names.txt";
		Write_Data_Object_4.open(PATH_NAME.c_str(), ios::out);
		Write_Data_Object_4 << User_name_for_input;
		Write_Data_Object_4.close();
		system("cls");
		cout << "Hello!" << User_name_for_input << "!" << endl;
		cout << "Start our amazing journey!";
		Sleep(3000);
		system("cls");
		cout << "Do you need to learn instructions?\n";
		cout << "0-No,1-Yes\n";
		string Judgment_data;
		int Judgment_data_INT = 0;
		while (1)
		{
			if (Judgment_data_INT == 3)
			{
				cout << "Error multiple times, automatic exit\n";
				break;
			}
			getline(cin, Judgment_data);
			if (Judgment_data == "1")
			{
				cout << "There is a instruction sets\n";
				cout << "The \"help\" directive brings up the instruction set and syntax\n";
				cout << "For example, the use of the \"out\" function is out + content\n";
				cout << "In short, the \"help\" function can give you the answer you want\n";
				Sleep(10000);
				break;
			}
			if (Judgment_data == "0")
			{
				break;
				cin.ignore();
			}
			else
			{
				cout << "Input error, please re-enter\n";
				Judgment_data_INT++;
			}
		}
		system("cls");
	}
	string User_name;
	ifstream Write_Data_Object_5;
	string PATH_NAME = PATH + "\\names.txt";
	Write_Data_Object_5.open(PATH_NAME.c_str(), ios::in);
	if (!Write_Data_Object_5.is_open())
	{
		User_name = "your";
	}
	else
	{
		char Temporary_transit_data1[1024] = { 0 };
		Write_Data_Object_5 >> Temporary_transit_data1;
		User_name = Temporary_transit_data1;
	}
	string PATH_SYSTEM = PATH + "\\system.txt";
	while (1)
	{
		int Determines_whether_the_command_is_a_runtime = 0;
		string User_input;
		cout << "\033[0;36m";
		
		cout << User_name <<"@Xpoy"<<"\033[0; 32m" << "~$ ";
		cout << "\033[0m";
		getline(cin, User_input);
		int The_user_enters_the_length = User_input.length();
		char* The_user_enters_a_dynamic_group = new char[The_user_enters_the_length];
		strcpy(The_user_enters_a_dynamic_group, User_input.c_str());
		if ((User_input[0] == 'o') && (User_input[1] == 'u') && (User_input[2] == 't') && (User_input[3] == ' '))
		{
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "out:";
			for (int For_loop_to_transfer_data1 = 4; For_loop_to_transfer_data1 < The_user_enters_the_length; For_loop_to_transfer_data1++)
			{
				cout << The_user_enters_a_dynamic_group[For_loop_to_transfer_data1];
				Determines_whether_the_command_is_a_runtime = 1;
				pp2 << The_user_enters_a_dynamic_group[For_loop_to_transfer_data1];
			}
			pp2 << "\n";
			pp2.close();
			cout << "\n";
		}
		if (User_input == "out")
		{
			cout << " \n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "out:error\n";
			pp2.close();
		}
		if ((The_user_enters_a_dynamic_group[0] == 'p') && (The_user_enters_a_dynamic_group[1] == 'r') && (The_user_enters_a_dynamic_group[2] == 'i') && (The_user_enters_a_dynamic_group[3] == 'n') && (The_user_enters_a_dynamic_group[4] == 't') && (The_user_enters_a_dynamic_group[5] == ' ') && (The_user_enters_a_dynamic_group[6] == 'h') && (The_user_enters_a_dynamic_group[7] == 'e') && (The_user_enters_a_dynamic_group[8] == 'l') && (The_user_enters_a_dynamic_group[9] == 'p'))
		{
			cout << "The \"print\" function is replaced by the \"out\" function\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "print:0\n";
			pp2.close();
		}
		if (User_input == "print")
		{
			cout << "The \"print\" function is replaced by the \"out\" function\nUse the \"out\" function\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "print:0\n";
		}
		if ((The_user_enters_a_dynamic_group[0] == 'c') && (The_user_enters_a_dynamic_group[1] == 'a') && (The_user_enters_a_dynamic_group[2] == 'l') && (The_user_enters_a_dynamic_group[3] == 'c') && (The_user_enters_the_length == 4))
		{
			system("calc");
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "calc:start\n";
			pp2.close();
		}
		if ((The_user_enters_a_dynamic_group[0] == 'n') && (The_user_enters_a_dynamic_group[1] == 'a') && (The_user_enters_a_dynamic_group[2] == 'm') && (The_user_enters_a_dynamic_group[3] == 'e') && (The_user_enters_the_length == 4))
		{
			ofstream file;
			string PATH_NAME = PATH + "\\names.txt";
			file.open(PATH_NAME, ios::out);
			cout << "Please enter your first name" << endl;
			string Enter_the_transition_user_name;
			cin >> Enter_the_transition_user_name;
			file << Enter_the_transition_user_name;
			file.close();
			User_name = Enter_the_transition_user_name;
			Determines_whether_the_command_is_a_runtime = 1;
			cin.ignore();
			system("cls");
			system("title BCP[5.0]");
			cout << "Bluff command prompt[version 5.0]\n";
			cout << "(c++) Microsoft Windows Users Wuzijie reserves this power\n";
			cout << "\n";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "name:";
			pp2 << Enter_the_transition_user_name;
			pp2 << "\n";
			pp2.close();
		}
		if (User_input == "name help")
		{
			cout << "name --- Change your name\n";
			cout << "column:name enter\n123 enter\n123$xxx\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "name help:help\n";
			pp2.close();
		}
		if (User_input == "ver")
		{
			cout << "The terminal version is 1.1\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "version:out\n";
			pp2.close();
		}
		if (User_input == "ver help")
		{
			cout << "version --- Check the version\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "version help:help\n";
			pp2.close();
		}
		if (User_input == "help")
		{
			cout << "Instruction set:\n";
			cout << "print(x) --- print characters\n";
			cout << "version --- Check the version\n";
			cout << "name --- Change your name\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "help:help\n";
			pp2.close();
		}
		if (User_input == "kill list")
		{
			system("tasklist");
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "kill list:list\n";
			pp2.close();
		}
		if (User_input == "import this")
		{
			cout << "This is made by Wu Zijie\nMade in C++\nStarting from February 10, 2023\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "import this:import this\n";
			pp2.close();
		}
		if (User_input == "exit")
		{
			break;
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "exit:exit\n";
			pp2.close();
		}
		if (User_input == "kill")
		{
			int fp = 0;
			string Kill_data_conversion;
			cout << "Please enter the process you want to end\n";
			cin >> Kill_data_conversion;
			int kill_data_length = Kill_data_conversion.length();
			char* kill_data = new char[kill_data_length];
			strcpy(kill_data, Kill_data_conversion.c_str());
			KillProcess(kill_data, fp);
			cin.ignore();
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "kill:";
			pp2 << Kill_data_conversion;
			if (fp == 0)
			{
				pp2 << "<No>";
			}
			else
			{
				pp2 << "<Yes>";
			}
			pp2 << "\n";
			pp2.close();
		}
		if (User_input == "clean")
		{
			system("cls");
			system("title BCP[5.0]");
			cout << "Bluff command prompt[version 5.0]\n";
			cout << "(c++) Microsoft Windows Users Wuzijie reserves this power\n";
			cout << "\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "clean:clean\n";
			pp2.close();
		}
		if (User_input == "baidu")
		{
			cout << "Please enter the information you want to enter\n";
			string Search_for_the_URL;
			string f = "https://www.baidu.com/s?wd=";
			getline(cin, Search_for_the_URL);
			string baidu123 = "start " + f + Search_for_the_URL;
			system(baidu123.c_str());
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "baidu:";
			pp2 << "<";
			pp2 << Search_for_the_URL;
			pp2 << ">\n";
			pp2.close();
		}
		if (User_input == "bing")
		{
			cout << "Please enter the information you want to enter\n";
			string Search_for_the_URL;
			string f = "https://cn.bing.com/search?q=";
			getline(cin, Search_for_the_URL);
			string baidu123 = "start " + f + Search_for_the_URL;
			system(baidu123.c_str());
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "bing:";
			pp2 << "<";
			pp2 << Search_for_the_URL;
			pp2 << "\n";
			pp2.close();
		}
		if (User_input == "cmd")
		{
			system("start cmd");
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "cmd:start\n";
			pp2.close();
		}
		if (User_input == "shutdown help")
		{
			cout << "shutdown --- shutdown this PC\nreboot --- reboot this PC\nlogout --- logout this PC\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "shutdown help:help\n";
			pp2.close();
		}
		if (User_input == "shutdown")
		{
			shutdown2 = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "shutdown:shutdown\n";
			pp2.close();
			break;
		}
		if (User_input == "reboot")
		{
			shutdown2 = 2;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "reboot:reboot";
			pp2.close();
			break;
		}
		if (User_input == "logout")
		{
			shutdown2 = 3;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "logout:logout\n";
			pp2.close();
			break;
		}
		if (User_input == "time")
		{
			time_t now = time(0);
			char* dt = ctime(&now);
			cout << "Time is " << dt << endl;
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "time:out";
			pp2 << "<";
			pp2 << "dt";
			pp2 << ">";
			pp2.close();
		}
		if (User_input == "[5.0]")
		{
			cout << "Thank you!\nBCP [5.0] breaks through 625 lines of code\n";
			Determines_whether_the_command_is_a_runtime = 1;
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "[5.0]:out";
			pp2.close();
		}
		if ((User_input[0] == 'l') && (User_input[1] == 's') && (User_input[2] == ' '))
		{
			int l2 = User_input.length();
			char* f = new char[l2 - 3]();
			int l3 = 0;
			int j22 = 0;
			int i = 3;
			for (; i < l2; i++)
			{
				f[j22] = User_input[i];
				j22++;
			}
			string f2;
			f2 = f;
			bool ppp = CheckFolderExist(f2);
			if (ppp == true)
			{
				string f3 = "dir " + f2;
				system(f3.c_str());
				ofstream pp2;
				pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
				pp2 << "ls:";
				pp2 << "<";
				pp2 << f2;
				pp2 << "><Yes>\n";
				pp2.close();
			}
			else
			{
				cout << "This is not a valid command\n";
				ofstream pp2;
				pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
				pp2 << "ls:";
				pp2 << "<";
				pp2 << f2;
				pp2 << "><No>\n";
				pp2.close();
			}
			Determines_whether_the_command_is_a_runtime = 1;
		}
		if ((User_input == "What is BCP [5.0]") || (User_input == "[5.0] help"))
		{
			cout << "BCP is Instruction set terminal\nBCP [4.1] is a patch release of BCP [5.0].\n";
			cout << "Because BCP [4.0] had some directory issues, it was modified by BCP [5.0].\n";
			cout << "The BCP [5.*] series may not be released at a later stage\n";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "[5.0]:help\n";
			pp2.close();
		}
		if ((User_input[0] == 'r') && (User_input[1] == 'e') && (User_input[2] == 'a') && (User_input[3] == 'd') && (User_input[4] == ' '))
		{
			int f2l = User_input.length() - 5;
			char* f2 = new char[f2l]();
			int i2 = 5;
			int i3 = 0;
			for (; i2 < User_input.length(); i2++)
			{
				f2[i3] = User_input[i2];
				i3++;
			}
			string a2 = f2;
			ifstream a;
			a.open(a2.c_str(), ios::in);
			if (!a.is_open())
			{
				cout << "Opening failed\n";
				a.close();
				ofstream pp2;
				pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
				pp2 << "read:Opening failed\n";
				pp2.close();
			}
			else
			{
				{
					char pddssd[1024] = { 0 };
					a >> pddssd;
					cout << pddssd << "\n";
					a.close();
					ofstream pp2;
					pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
					pp2 << "read:" << pddssd << "\n";
					pp2.close();
				}
			}
			Determines_whether_the_command_is_a_runtime = 1;

		}
		if (User_input == "hide")
		{
			cout << "\033[?25l";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "appearance:hide";
			pp2.close();
			Determines_whether_the_command_is_a_runtime = 1;
		}
		if (User_input == "appear")
		{
			cout << "\033[?25h";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "appearance:appear";
			pp2.close();
			Determines_whether_the_command_is_a_runtime = 1;
		}
		if (User_input == "flashing" || User_input == "flash" || User_input == "fla")
		{
			cout << "\033[5m ";
			system("cls");
			system("title BCP[5.0]");
			cout << "Bluff command prompt[version 5.0]\n";
			cout << "(c++) Microsoft Windows Users Wuzijie reserves this power\n";
			cout << "\n";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "appearance:flashing";
			pp2.close();
			Determines_whether_the_command_is_a_runtime = 1;
		}
		if (User_input == "off property" || User_input == "OP")
		{
			cout << "\033[0m ";
			system("cls");
			system("title BCP[5.0]");
			cout << "Bluff command prompt[version 5.0]\n";
			cout << "(c++) Microsoft Windows Users Wuzijie reserves this power\n";
			cout << "\n";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "appearance:the property is off";
			pp2.close();
			Determines_whether_the_command_is_a_runtime = 1;
		}
		if (Determines_whether_the_command_is_a_runtime == 0)
		{
			cout << "\"" << User_input << "\"" << "This is not a valid command\n";
			ofstream pp2;
			pp2.open(PATH_SYSTEM.c_str(), ios::out | ios::app);
			pp2 << "error:This is not a valid command\n";
			pp2 << "<";
			pp2 << User_input;
			pp2 << ">\n";
			pp2.close();
		}
	}
	if (shutdown2 == 1)
	{
		system("shutdown /p");
	}
	if (shutdown2 == 2)
	{
		system("shutdown /r");
	}
	if (shutdown2 == 3)
	{
		system("shutdown /l");
	}

}