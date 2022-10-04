#include <iostream>
#include <string>
#include <algorithm>
#include "Calculator.h"
using namespace std;
/*
    UTILITY FUNCTIONS
    -- Some necessary function to make program functional
*/

// Returns true if s is a number else false
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int main()
{
    Calculator cal;
    bool quit = 0;
    string menus[] =
    {
        "Calculator",
        "History",
        "Exit"
    };
    int sizeOfMenus = sizeof(menus)/sizeof(string);
    string input;

    // PROGRAM START HERE!
    while(!quit)
    {
        system("cls"); // clear the screen
        // Print the menus
        cout << "Scientific Calculator" << endl;
        cout << "=====================" << endl;
        for(int i=0; i < sizeOfMenus; i++)
            cout << i+1 << " " << menus[i] << endl;

        cout << ">>> ";
        cin >> input; cin.ignore();

        // Check whether user inputted word or number
        if(isNumber(input)) {
            if(input == "1")
            {
                // some functions
                bool quitCal = false;
                while(!quitCal) {
                    // Print the banner
                    cout << "\n\nCalculator" << endl;
                    cout << "=====================\n" << endl;
                    cout << ">>> ";

                    string val;
                    getline(cin, val);
                    cal.setStorage(val);

                    string tmp = "";
                    int indexComponent = 0;
                    for(int i = 0; i < val.length(); i++) {
                        if(val[i] != ' ') {
                            // check for operators
                            // TODO : revised... so next it use array of operators. not like this
                            if(val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/') {
                                tmp += val[i];
                                cal.setComponents(tmp, indexComponent);

                                tmp = "";
                                indexComponent++;
                                continue;

                            } else {
                                tmp += val[i];
                                if (isdigit(val[i+1])) // if next string is integer, continue the loop to next loop immediately
                                    continue;
                                else {
                                    cal.setComponents(tmp, indexComponent);

                                    tmp = "";
                                    indexComponent++;
                                }
                            }
                        }
                    }

                    // additional menu for the calculator side
                    int tmpInpt;
                    cout << "\n===================" << endl;
                    cout << "1. Continue" << endl;
                    cout << "2. Back to menu" << endl;
                    cin >> tmpInpt; cin.ignore();
                    if(tmpInpt == 1)
                        system("cls");
                    else if(tmpInpt == 2)
                        quitCal = true;
                }
            }

            else if(input == "2")
            {
                // some functions
                cal.printStorage();
                system("pause");
            }

            // exit
            else if (input == "3")
            {
                cout << "Bye Thank You!" << endl;
                cout << "See You Next Time" << endl;
                quit = true;
            }

            else
            {
                // If user entered more than size of menus
                cout << "Invalid Input!" << endl;
                cout << "Numbers allowed only from 1 to " << sizeOfMenus << endl;
                system("pause");
            }
        } else {
            // If user entered a word, not a number
            cout << "Invalid Type of Input!" << endl;
            cout << "Only numbers are allowed!" << endl;
            system("pause");
        }

    }

    return 0;
}
