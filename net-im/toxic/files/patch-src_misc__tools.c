--- src/misc_tools.c.orig	2016-09-23 17:05:05 UTC
+++ src/misc_tools.c
@@ -26,6 +26,8 @@
 #include <time.h>
 #include <limits.h>
 #include <dirent.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 
 #include <sys/stat.h>
 #include <arpa/inet.h>
