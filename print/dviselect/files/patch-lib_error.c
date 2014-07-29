--- lib/error.c.orig	Wed Nov 15 04:19:40 1989
+++ lib/error.c	Wed Oct 15 06:38:57 2003
@@ -18,7 +18,8 @@
  */
 
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
+#include <errno.h>
 
 #ifdef lint
 
@@ -31,20 +32,15 @@
 #else lint
 
 extern char *ProgName;
-extern int errno;
-extern char *sys_errlist[];
-extern int sys_nerr;
 
-error(va_alist)
-	va_dcl
+error(char *fmt,...)
 {
 	va_list l;
 	int quit, e;
-	char *fmt;
 
 	(void) fflush(stdout);	/* sync error messages */
 	(void) fprintf(stderr, "%s: ", ProgName);
-	va_start(l);
+	va_start(l,fmt);
 	/* pick up the constant arguments: quit, errno, printf format */
 	quit = va_arg(l, int);
 	e = va_arg(l, int);
@@ -69,15 +65,13 @@
 		exit(quit);
 }
 
-panic(va_alist)
-	va_dcl
+panic(char *fmt,...)
 {
 	va_list l;
-	char *fmt;
 
 	(void) fflush(stdout);
 	(void) fprintf(stderr, "%s: panic: ", ProgName);
-	va_start(l);
+	va_start(l,fmt);
 	/* pick up the constant argument: printf format */
 	fmt = va_arg(l, char *);
 #if defined(sys5) || defined(HAVE_VPRINTF)
