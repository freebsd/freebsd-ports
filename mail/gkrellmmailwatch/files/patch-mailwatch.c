--- mailwatch.c.orig	Mon Apr 16 23:00:40 2001
+++ mailwatch.c	Mon Apr 16 23:02:26 2001
@@ -19,6 +19,7 @@
 */
 
 #include <dirent.h>
+#include <sys/types.h>
 #include <utime.h>
 #include <string.h>
 #include "mailwatch.h"
