--- util.c.orig	Thu Jan 30 11:22:45 2003
+++ util.c	Thu Jan 30 11:22:54 2003
@@ -40,6 +40,7 @@
 #include <assert.h>
 #include <stdarg.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/uio.h>
 #include <sys/param.h>
 #include <sys/socket.h>
@@ -55,7 +56,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 #include <dirent.h>
