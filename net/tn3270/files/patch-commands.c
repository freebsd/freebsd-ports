--- telnet/commands.c.orig	Tue Aug 31 01:52:04 1999
+++ telnet/commands.c	Tue Jan 25 14:15:56 2005
@@ -55,7 +55,7 @@
 #include <netdb.h>
 #include <ctype.h>
 #include <pwd.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <errno.h>
 
 #include <arpa/telnet.h>
@@ -95,7 +95,9 @@
 extern char **genget();
 extern int Ambiguous();
 
-static call();
+typedef int (*intrtn_t)();
+
+static call(intrtn_t routine, ...);
 
 typedef struct {
 	char	*name;		/* command name */
@@ -2452,19 +2454,14 @@
  * Call routine with argc, argv set from args (terminated by 0).
  */
 
-    /*VARARGS1*/
     static
-call(va_alist)
-    va_dcl
+call(intrtn_t routine, ...)
 {
     va_list ap;
-    typedef int (*intrtn_t)();
-    intrtn_t routine;
     char *args[100];
     int argno = 0;
 
-    va_start(ap);
-    routine = (va_arg(ap, intrtn_t));
+    va_start(ap, routine);
     while ((args[argno++] = va_arg(ap, char *)) != 0) {
 	;
     }
