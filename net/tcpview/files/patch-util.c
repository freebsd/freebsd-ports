--- util.c.orig	Fri Apr 23 04:40:36 1993
+++ util.c	Tue Oct 28 01:59:11 2003
@@ -64,7 +64,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <sys/file.h>
 #include <sys/stat.h>
 
@@ -277,16 +277,13 @@
 }
 
 void
-error(va_alist)
-	va_dcl
+error(char *cp, ...)
 {
-	register char *cp;
 	va_list ap;
 
 	(void)fprintf(stderr, "%s: ", stripdir(program_name));
 
-	va_start(ap);
-	cp = va_arg(ap, char *);
+	va_start(ap, cp);
 	(void)vfprintf(stderr, cp, ap);
 	va_end(ap);
 	if (*cp) {
@@ -301,16 +298,13 @@
 
 /* VARARGS */
 void
-warning(va_alist)
-	va_dcl
+warning(char *cp, ...)
 {
-	register char *cp;
 	va_list ap;
 
 	(void)fprintf(stderr, "%s: warning: ", stripdir(program_name));
 
-	va_start(ap);
-	cp = va_arg(ap, char *);
+	va_start(ap, cp);
 	(void)vfprintf(stderr, cp, ap);
 	va_end(ap);
 	if (*cp) {
