--- mailwatch.c.orig	Sun Aug 12 07:15:30 2001
+++ mailwatch.c	Fri Aug 17 15:20:54 2001
@@ -19,6 +19,7 @@
 */
 
 #include <dirent.h>
+#include <sys/types.h>
 #include <time.h>
 #include <utime.h>
 #include <string.h>
