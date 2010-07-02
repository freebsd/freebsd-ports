#include <unistd.h>
int main(int argc,char** argv)
{
    setsid();
    execvp(argv[1], argv+1);
    return 0;
}
