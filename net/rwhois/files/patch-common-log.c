--- common/log.c.orig	Tue Oct 28 02:26:55 2003
+++ common/log.c	Tue Oct 28 02:28:25 2003
@@ -139,15 +139,12 @@
 /* log_error: prints a error message to the console. This is intended
      for server side errors only. */
 void
-log_error(va_alist)
-  va_dcl
+log_error(char *format, ...)
 {
   va_list   list;
-  char      *format;
   char      err_buf[MAX_LINE];
   
-  va_start(list);
-  format = va_arg(list, char *);
+  va_start(list, format);
 
 #ifdef HAVE_VSNPRINTF
   vsnprintf(err_buf, sizeof(err_buf), format, list);
@@ -164,15 +161,12 @@
 /* log_warning: prints a warning message to the console. This is intended
    for server side warnings only. */
 void
-log_warning(va_alist)
-  va_dcl
+log_warning(char *format, ...)
 {
   va_list   list;
-  char      *format;
   char      err_buf[MAX_LINE];
   
-  va_start(list);
-  format = va_arg(list, char *);
+  va_start(list, format);
 
 #ifdef HAVE_VSNPRINTF
   vsnprintf(err_buf, sizeof(err_buf), format, list);
