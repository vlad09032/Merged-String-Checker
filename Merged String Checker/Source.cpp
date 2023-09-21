/*
At a job interview, you are challenged to write an algorithm to check if a given string, s, can
be formed from two other strings, part1 and part2.

The restriction is that the characters in part1 and part2 should be in the same order as in s.

The interviewer gives you the following example and tells you to figure out the rest from the
given test cases.

For example:

'codewars' is a merge from 'cdw' and 'oears':

    s:  c o d e w a r s   = codewars
part1:  c   d   w         = cdw
part2:    o   e   a r s   = oears
*/
#include<iostream>
#include<string>

bool is_merge(const std::string& s, const std::string part1,
    const std::string part2)
{
    int itog{ 0 };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        for (int j{ 0 }; j < s.length(); j++)
        {
            if (part1 != "" && j<=part1.length())
            {
                if (s[i] == part1[j])
                {
                    ++itog;
                   
                    break;
                }
            }
        
            if (part2 != "" && j <= part2.length())
            {
                if (s[i] == part2[j])
                {
                    ++itog;
                    
                    break;
                }
            }
        }

    }
    
    return (itog == s.length()) && (s.length() == (part1.length() + part2.length()));
}
bool test_is_merge(const std::string& s, const std::string part1,
    const std::string part2)
{   
    std::string p1 = part1;
    std::string p2 = part2;
    int itog{ 0 };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        for (int j{ 0 }; j < s.length(); j++)
        {
            if (p1 != "" && j <= p1.length())
            {
                
                if (s[i] == p1[j])
                {
                    ++itog;
                    p1.erase(j, 1);
                    break;
                }
            }
            if (p2 != "" && j <= p2.length())
            {
                if (s[i] == p2[j])
                {
                    ++itog;
                    p2.erase(j, 1);
                    break;
                }
                
            }
            break;
        }
    }
   
     return (itog == s.length()) && (s.length() == (part1.length() + part2.length()));
}

int main()
{
    std::cout<<test_is_merge("acab", "ab", "ac");
}