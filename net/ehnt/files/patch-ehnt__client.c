
$FreeBSD$

--- ehnt_client.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_client.c	Thu Nov 14 22:12:07 2002
@@ -89,7 +89,7 @@
    if (FD_ISSET(sockfd,&read_fds)) {
      ehnt_client_processmessage(sockfd,routeraddr,my_ehnt_struct);
    }
-   if (FD_ISSET(STDIN_FILENO,&read_fds)) {
+   if (e_cfg->mode != EM_COLONDUMP && FD_ISSET(STDIN_FILENO,&read_fds)) {
      char key;
      key=getkey();
      switch (key) {
