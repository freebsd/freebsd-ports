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
