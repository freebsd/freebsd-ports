--- omfuncs.c.orig	2010-07-05 14:29:11.000000000 +0400
+++ omfuncs.c	2010-07-05 14:30:01.000000000 +0400
@@ -6,6 +6,8 @@
 #include <time.h>
 #include <string.h>
 #include <stdarg.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <stdlib.h>
