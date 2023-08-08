--- keama/keama.c.orig	2022-09-28 14:39:15 UTC
+++ keama/keama.c
@@ -22,6 +22,7 @@
  */
 
 #include <sys/errno.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <assert.h>
 #include <fcntl.h>
