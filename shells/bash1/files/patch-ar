--- lib/readline/display.c.orig	Fri Aug 29 12:28:33 2003
+++ lib/readline/display.c	Fri Aug 29 12:29:29 2003
@@ -1020,13 +1020,11 @@
    mini-modeline. */
 
 #if defined (HAVE_VARARGS_H)
-rl_message (va_alist)
-     va_dcl
+rl_message (char *format, ...)
 {
-  char *format;
   va_list args;
 
-  va_start (args);
+  va_start (args, format);
   format = va_arg (args, char *);
   vsprintf (msg_buf, format, args);
   va_end (args);
