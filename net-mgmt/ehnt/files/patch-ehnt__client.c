
$FreeBSD$

--- ehnt_client.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_client.c	Mon May 24 11:59:17 2004
@@ -69,7 +69,8 @@
    printf("Warning: can't catch interrupt signal\n");
  }
  fflush(stdout);
- set_term(SET_TERM_RAW);
+ if (e_cfg->mode != EM_COLONDUMP)
+   set_term(SET_TERM_RAW);
  setbuf(stdout,NULL);
 
  for ( ; ; ) {
@@ -78,7 +79,8 @@
    int maxfd=sockfd;
    
    FD_ZERO(&read_fds);
-   FD_SET(STDIN_FILENO,&read_fds);
+   if (e_cfg->mode != EM_COLONDUMP)
+     FD_SET(STDIN_FILENO,&read_fds);
    FD_SET(sockfd,&read_fds);
 
    fflush(stdout);
@@ -89,7 +91,7 @@
    if (FD_ISSET(sockfd,&read_fds)) {
      ehnt_client_processmessage(sockfd,routeraddr,my_ehnt_struct);
    }
-   if (FD_ISSET(STDIN_FILENO,&read_fds)) {
+   if (e_cfg->mode != EM_COLONDUMP && FD_ISSET(STDIN_FILENO,&read_fds)) {
      char key;
      key=getkey();
      switch (key) {
