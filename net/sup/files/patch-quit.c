--- quit.c.orig	Fri Jul 25 23:20:04 2003
+++ quit.c	Fri Jul 25 23:22:08 2003
@@ -50,17 +50,15 @@
  */
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 
-quit (status, fmt, va_alist)
-int status;
-char *fmt;
-va_dcl
+quit (char *fmt,...)
 {
+	int status;
+	char *fmt;
 	va_list args;
-
 	fflush(stdout);
-	va_start(args);
+	va_start(args,fmt);
 	(void) vfprintf(stderr, fmt, args);
 	va_end(args);
 	exit(status);
