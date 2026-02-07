--- util.c.orig	1993-04-22 20:40:36 UTC
+++ util.c
@@ -64,7 +64,7 @@ static char rcsid[] =
 #include <sys/types.h>
 #include <sys/time.h>
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <sys/file.h>
 #include <sys/stat.h>
 
@@ -277,16 +277,13 @@ void
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
@@ -301,16 +298,13 @@ void
 
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
