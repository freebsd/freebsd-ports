--- clients/telnet/commands.c.orig	Thu Aug 17 00:38:46 2000
+++ clients/telnet/commands.c	Tue Sep  7 20:39:04 2004
@@ -83,7 +83,17 @@
 #include <signal.h>
 #include <ctype.h>
 #include <pwd.h>
+
+#ifdef HAVE_STDARG_H
+#include <stdarg.h>
+#define VA_START(a, b) va_start((a), (b))
+#define va_alist ...
+#define va_dcl
+#else
 #include <varargs.h>
+#define VA_START(a, b) va_start((a))
+#endif
+
 #include <errno.h>
 
 #include <arpa/telnet.h>
@@ -122,7 +132,9 @@
 extern int Ambiguous();
 extern void herror();
 
-static int call();
+typedef int (*intrtn_t)();
+
+static int call(intrtn_t routine, va_alist);
 
 typedef struct {
     char *name;		/* command name */
@@ -2092,17 +2104,14 @@
 
     /*VARARGS1*/
     static int
-call(va_alist)
+call(intrtn_t routine, va_alist)
     va_dcl
 {
     va_list ap;
-    typedef int (*intrtn_t)();
-    intrtn_t routine;
     char *args[100];
     int argno = 0;
 
-    va_start(ap);
-    routine = (va_arg(ap, intrtn_t));
+    VA_START(ap, routine);
     while ((args[argno++] = va_arg(ap, char *)) != 0) {
 	;
     }
