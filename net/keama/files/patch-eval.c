--- keama/eval.c.orig	2022-09-28 14:39:15 UTC
+++ keama/eval.c
@@ -25,6 +25,7 @@
 
 #include <sys/errno.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <ctype.h>
 #include <netdb.h>
