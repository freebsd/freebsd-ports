--- xnntputil.c.orig	Thu Jan 30 11:22:21 2003
+++ xnntputil.c	Thu Jan 30 11:22:27 2003
@@ -30,6 +30,7 @@
 
 #include <assert.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/uio.h>
 #include <sys/param.h>
 #include <sys/socket.h>
@@ -45,7 +46,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
 #include <dirent.h>
