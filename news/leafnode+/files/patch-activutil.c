--- activutil.c.orig	Thu Jan 30 11:21:44 2003
+++ activutil.c	Thu Jan 30 11:21:58 2003
@@ -44,6 +44,7 @@
 #endif
 
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/uio.h>
 #include <sys/param.h>
 #include <sys/socket.h>
@@ -59,7 +60,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 #include <dirent.h>
