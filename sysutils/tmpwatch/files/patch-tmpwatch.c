--- tmpwatch.c.orig	Wed Feb 20 22:42:57 2002
+++ tmpwatch.c	Wed Feb 20 23:14:48 2002
@@ -28,7 +28,6 @@
 #include <utime.h>
 #include <unistd.h>
 #include <paths.h>
-#include <mntent.h>
 
 #define LOG_REALDEBUG	1
 #define LOG_DEBUG	2
@@ -324,6 +323,7 @@
 	    if (*significant_time >= killTime)
 		continue;
 
+#if 0
 	    /* check if it is an ext3 journal file */
 	    if ((strcmp(ent->d_name, ".journal") == 0) &&
 		(sb.st_uid == 0)) {
@@ -352,6 +352,7 @@
 		    continue;
 		}
 	    }
+#endif
 	    
 	    if ((flags & FLAG_ALLFILES) ||
 		S_ISREG(sb.st_mode) ||
