
$FreeBSD$

--- ehnt_client.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_client.c	Mon Aug  9 23:49:05 2004
@@ -27,6 +27,9 @@
 static void sig_int (int);
 char getkey();
 
+
+ssize_t read_n(int fd, void *vptr, size_t n);
+
 int ehnt_client(char * servername, int serverport, struct ehnt_struct *my_ehnt_struct ) {
  char ips[100];
   int c;
@@ -69,7 +72,8 @@
    printf("Warning: can't catch interrupt signal\n");
  }
  fflush(stdout);
- set_term(SET_TERM_RAW);
+ if (e_cfg->mode != EM_COLONDUMP)
+   set_term(SET_TERM_RAW);
  setbuf(stdout,NULL);
 
  for ( ; ; ) {
@@ -78,7 +82,8 @@
    int maxfd=sockfd;
    
    FD_ZERO(&read_fds);
-   FD_SET(STDIN_FILENO,&read_fds);
+   if (e_cfg->mode != EM_COLONDUMP)
+     FD_SET(STDIN_FILENO,&read_fds);
    FD_SET(sockfd,&read_fds);
 
    fflush(stdout);
@@ -89,7 +94,7 @@
    if (FD_ISSET(sockfd,&read_fds)) {
      ehnt_client_processmessage(sockfd,routeraddr,my_ehnt_struct);
    }
-   if (FD_ISSET(STDIN_FILENO,&read_fds)) {
+   if (e_cfg->mode != EM_COLONDUMP && FD_ISSET(STDIN_FILENO,&read_fds)) {
      char key;
      key=getkey();
      switch (key) {
