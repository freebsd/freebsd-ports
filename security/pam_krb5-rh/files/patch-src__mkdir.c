--- ./src/mkdir.c.orig	2012-09-12 22:34:04.000000000 -0400
+++ ./src/mkdir.c	2012-12-14 22:26:24.000000000 -0500
@@ -34,6 +34,8 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/syslimits.h>
+#include <sys/limits.h>
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
