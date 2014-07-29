--- icb/c_log.c.orig	Sat May 11 23:59:42 2002
+++ icb/c_log.c	Sun May 12 00:00:20 2002
@@ -7,6 +7,9 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #ifdef HAVE_TIME_H
 #include <time.h>
 #endif
@@ -30,7 +33,8 @@
 	time_t time();
 	struct tm *t, *localtime();
 	time_t clock;
-	extern int errno, sys_nerr;
+	extern int errno;
+	extern const int sys_nerr;
 
 	/* determine pathname to use */
 	if (path == NULL || *path == '\0') {
@@ -43,17 +47,17 @@
 	/* expand a tilde style path */
 	if (*path == '~')
 		if ((path = tildexpand(path)) == NULL) {
-			strcpy(TRET, "c_log: bad login id in path");
+			strcpy(Tcl_GetStringResult(interp), "c_log: bad login id in path");
 			return(-1);
 		}
 	
 	/* open the session log */
 	if ((logfp = fopen(path, "a")) == NULL) {
 		if (errno > sys_nerr)
-		   sprintf(TRET,
+		   sprintf(Tcl_GetStringResult(interp),
 		    "c_log: can't open \"%s\": errno %d", path, errno);
 		else
-		   sprintf(TRET,
+		   sprintf(Tcl_GetStringResult(interp),
 		    "c_log: can't open \"%s\": %s", path, strerror(errno));
 		return(-1);
 	}
@@ -61,10 +65,10 @@
 	/* protect the logfile against others */
 	if (fchmod((int)(fileno(logfp)), 0600) != 0) {
 		if (errno > sys_nerr)
-		   sprintf(TRET,
+		   sprintf(Tcl_GetStringResult(interp),
 		    "c_log: can't fchmod \"%s\": errno %d", path, errno);
 		else
-		   sprintf(TRET,
+		   sprintf(Tcl_GetStringResult(interp),
 		    "c_log: can't fchmod \"%s\": %s", path, strerror(errno));
 		fclose(logfp);
 		logfp = NULL;
@@ -146,7 +150,7 @@
 				return(TCL_ERROR);
 	} else {
 		if (logging()) {
-			sprintf(TRET, "c_log: session logging already on");
+			sprintf(Tcl_GetStringResult(interp), "c_log: session logging already on");
 			return(TCL_ERROR);
 		} else
 			if (startsessionlog(interp, argv[1]) < 0)
