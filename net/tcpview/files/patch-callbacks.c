--- callbacks.c.orig	1993-04-22 21:22:59 UTC
+++ callbacks.c
@@ -42,7 +42,7 @@ static char rcsid[] =
 #include <stdlib.h>
 #endif
 
-#include <varargs.h>
+#include <stdarg.h>
 #include <sys/types.h>
 #include <sys/time.h>
 #include <string.h>
@@ -66,7 +66,7 @@ extern Widget packet_label;
 extern Widget hex_text_widget;        /* hex (bottom) window */
 extern Widget packet_label;
 
-extern char *sys_errlist[];
+extern __const char *__const sys_errlist[];
 
 #ifdef __STDC__
 void redisplay_current_list(void);
@@ -726,32 +726,35 @@ void xperror(str)
 }
 
 
-void eprint(va_alist)
-     va_dcl
+void eprintv(char *fmt, va_list ap)
 {
+  char str[128];
+
+  (void)vsprintf(str, fmt, ap);
+  ErrorDialog(summary_list_widget, "error", str);
+}
+
+
+void eprint(char *fmt, ...)
+{
   va_list args;
-  char *fmt, str[128];
 
-  va_start(args);
-  fmt = va_arg(args, char *);
-  (void)vsprintf(str,fmt,args);
+  va_start(args, fmt);
+  eprintv(fmt, args);
   va_end(args);
-
-  ErrorDialog(summary_list_widget,"error",str);
 }
 
-void iprint(va_alist)
-     va_dcl
+
+void iprint(char *fmt, ...)
 {
   va_list args;
-  char *fmt, str[128];
+  char str[128];
   Widget widget;
   XmString ms;
   Arg a[2];
   int n;
 
-  va_start(args);
-  fmt = va_arg(args, char *);
+  va_start(args, fmt);
   (void)vsprintf(str,fmt,args);
   va_end(args);
 
