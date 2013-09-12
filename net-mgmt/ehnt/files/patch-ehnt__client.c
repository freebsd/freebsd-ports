
$FreeBSD$

--- ehnt_client.c.orig
+++ ehnt_client.c
@@ -27,6 +27,11 @@
 static void sig_int (int);
 char getkey();
 
+
+ssize_t read_n(int fd, void *vptr, size_t n);
+
+void ehnt_client_processmessage(int sockfd,struct in_addr routeraddr, struct ehnt_struct *my_ehnt_struct);
+
 int ehnt_client(char * servername, int serverport, struct ehnt_struct *my_ehnt_struct ) {
  char ips[100];
   int c;
@@ -69,7 +74,8 @@
    printf("Warning: can't catch interrupt signal\n");
  }
  fflush(stdout);
- set_term(SET_TERM_RAW);
+ if (e_cfg->mode != EM_COLONDUMP)
+   set_term(SET_TERM_RAW);
  setbuf(stdout,NULL);
 
  for ( ; ; ) {
@@ -78,7 +84,8 @@
    int maxfd=sockfd;
    
    FD_ZERO(&read_fds);
-   FD_SET(STDIN_FILENO,&read_fds);
+   if (e_cfg->mode != EM_COLONDUMP)
+     FD_SET(STDIN_FILENO,&read_fds);
    FD_SET(sockfd,&read_fds);
 
    fflush(stdout);
@@ -89,7 +96,7 @@
    if (FD_ISSET(sockfd,&read_fds)) {
      ehnt_client_processmessage(sockfd,routeraddr,my_ehnt_struct);
    }
-   if (FD_ISSET(STDIN_FILENO,&read_fds)) {
+   if (e_cfg->mode != EM_COLONDUMP && FD_ISSET(STDIN_FILENO,&read_fds)) {
      char key;
      key=getkey();
      switch (key) {
@@ -125,7 +132,7 @@
  } /* for ( ; ; ) */
 }
 
-int ehnt_client_processmessage(int sockfd,struct in_addr routeraddr, struct ehnt_struct *my_ehnt_struct ) {
+void ehnt_client_processmessage(int sockfd,struct in_addr routeraddr, struct ehnt_struct *my_ehnt_struct ) {
   int c,i;
   char mesg[MAXPACKET];
   struct flow_ver5_hdr * flowhdr;
