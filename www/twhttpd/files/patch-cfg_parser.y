--- cfg_parser.y.orig	Sat Aug 31 12:41:16 2002
+++ cfg_parser.y	Mon Jun 26 02:40:51 2006
@@ -27,10 +27,10 @@
 #include       <regex.h>
 #include       <errno.h>
 #include       <stdio.h>
-#include       <arpa/inet.h>
 #include       <sys/types.h>
 #include       <sys/socket.h>
 #include       <netinet/in.h>
+#include       <arpa/inet.h>
 
 #include       "config.h"
 #include       "cfg_functions.h"
