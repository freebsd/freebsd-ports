*** src/console/console.c.orig	Sun Jun 20 13:43:02 2004
--- src/console/console.c	Sat Jul  3 10:48:13 2004
***************
*** 63,69 ****
  
  /* Forward referenced functions */
  static void terminate_console(int sig);
! int get_cmd(FILE *input, const char *prompt, BSOCK *sock, int sec);
  static int do_outputcmd(FILE *input, BSOCK *UA_sock);
  void senditf(const char *fmt, ...);
  void sendit(const char *buf);
--- 63,69 ----
  
  /* Forward referenced functions */
  static void terminate_console(int sig);
! int get_cmd(FILE *input, char *prompt, BSOCK *sock, int sec);
  static int do_outputcmd(FILE *input, BSOCK *UA_sock);
  void senditf(const char *fmt, ...);
  void sendit(const char *buf);
***************
*** 200,206 ****
  
  static void read_and_process_input(FILE *input, BSOCK *UA_sock) 
  {
!    const char *prompt = "*";
     bool at_prompt = false;
     int tty_input = isatty(fileno(input));
     int stat;
--- 200,206 ----
  
  static void read_and_process_input(FILE *input, BSOCK *UA_sock)
  {
!    char *prompt = "*";
     bool at_prompt = false;
     int tty_input = isatty(fileno(input));
     int stat;
***************
*** 499,510 ****
  #ifdef HAVE_READLINE
  #define READLINE_LIBRARY 1
  #undef free
  #include "readline.h"
  #include "history.h"
  
- 
  int 
! get_cmd(FILE *input, const char *prompt, BSOCK *sock, int sec)
  {
     char *line;
  
--- 499,510 ----
  #ifdef HAVE_READLINE
  #define READLINE_LIBRARY 1
  #undef free
+ #include <stdio.h>
  #include "readline.h"
  #include "history.h"
  
  int
! get_cmd(FILE *input, char *prompt, BSOCK *sock, int sec)
  {
     char *line;
  
