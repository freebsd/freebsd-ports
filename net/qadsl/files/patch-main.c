*** main.c.orig	Thu Dec 13 21:41:36 2001
--- main.c	Thu Dec 13 21:47:38 2001
***************
*** 32,38 ****
  char send_msg[MAXDATASIZE], get_msg[MAXDATASIZE];
  char user[MAXLEN], pass[MAXLEN], serv[MAXLEN], deamon_s[MAXLEN], deamon_t[MAXLEN], deamon_d[MAXLEN];
  
! char *conf="/etc/qadsl.conf";
  
  int main(int argc, char *argv[])
  {
--- 32,38 ----
  char send_msg[MAXDATASIZE], get_msg[MAXDATASIZE];
  char user[MAXLEN], pass[MAXLEN], serv[MAXLEN], deamon_s[MAXLEN], deamon_t[MAXLEN], deamon_d[MAXLEN];
  
! char *conf= CONF;
  
  int main(int argc, char *argv[])
  {
