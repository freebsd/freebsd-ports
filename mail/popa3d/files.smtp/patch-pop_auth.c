--- pop_auth.c.orig	Mon Jul 16 11:51:30 2001
+++ pop_auth.c	Mon Jul 16 11:54:35 2001
@@ -12,6 +12,8 @@
 #include "protocol.h"
 #include "pop_auth.h"
 
+char *client_addr(int);
+
 static char *pop_user, *pop_pass;
 
 static int pop_auth_quit(char *params)
