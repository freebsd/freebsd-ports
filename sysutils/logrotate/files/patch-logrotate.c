--- logrotate.c.orig	Fri Aug  4 20:27:38 2000
+++ logrotate.c	Fri Jul 18 15:20:13 2003
@@ -1,9 +1,7 @@
-#include <alloca.h>
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <getopt.h>
 #include <popt.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -395,8 +393,7 @@
 	    if (log->pre && !(log->flags & LOG_FLAG_SHAREDSCRIPTS)) {
 		message(MESS_DEBUG, "running prerotate script\n");
 		if (runScript(log->files[logNum], log->pre)) {
-		    fprintf(errorFile, "error running prerotate script -- 
-				leaving old log in place\n");
+		    fprintf(errorFile, "error running prerotate script -- leaving old log in place\n"); 
 		    hasErrors = 1;
 		}
 	    }
@@ -471,6 +468,9 @@
 		}
 	    }
 
+	    message(MESS_DEBUG, "sleep 10 to wait daemon close log\n");
+	    sleep(10);
+
 	    if (!hasErrors && !log->rotateCount) {
 		message(MESS_DEBUG, "removing rotated log (rotateCount == 0)");
 		if (unlink(finalName)) {
@@ -634,8 +634,8 @@
     if (log->pre && (log->flags & LOG_FLAG_SHAREDSCRIPTS)) {
 	message(MESS_DEBUG, "running shared prerotate script\n");
 	if (runScript(log->pattern, log->pre)) {
-	    fprintf(errorFile, "error running shared prerotate script for %s-- 
-			leaving old logs in place\n", log->pattern);
+	    fprintf(errorFile, "error running shared prerotate script for %s-- "
+		"leaving old logs in place\n", log->pattern);
 	    hasErrors = 1;
 	}
     }
