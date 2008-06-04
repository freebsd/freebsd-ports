--- libopenvas/ftp_funcs.c.orig	2008-04-26 23:23:23.000000000 +0900
+++ libopenvas/ftp_funcs.c	2008-04-26 23:24:01.000000000 +0900
@@ -32,6 +32,7 @@
 #include <netinet/in.h>
 
 #include "network.h"
+#include <sys/socket.h>
 
 int ftp_log_in(int soc, char * username, char * passwd)
 {
