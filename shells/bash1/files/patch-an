--- error.c.orig	Fri Aug 29 12:21:42 2003
+++ error.c	Fri Aug 29 12:24:18 2003
@@ -22,7 +22,7 @@
 #include <fcntl.h>
 
 #if defined (HAVE_VFPRINTF)
-#include <varargs.h>
+#include <stdarg.h>
 #endif
 
 #include <errno.h>
@@ -121,18 +121,15 @@
 #else /* We have VARARGS support, so use it. */
 
 void
-programming_error (va_alist)
-     va_dcl
+programming_error (char *format, ...)
 {
   va_list args;
-  char *format;
 
 #if defined (JOB_CONTROL)
   give_terminal_to (shell_pgrp);
 #endif /* JOB_CONTROL */
 
-  va_start (args);
-  format = va_arg (args, char *);
+  va_start (args, format);
   vfprintf (stderr, format, args);
   fprintf (stderr, "\n");
   va_end (args);
@@ -144,15 +141,12 @@
 }
 
 void
-report_error (va_alist)
-     va_dcl
+report_error (char *format, ...)
 {
   va_list args;
-  char *format;
 
   fprintf (stderr, "%s: ", get_name_for_error ());
-  va_start (args);
-  format = va_arg (args, char *);
+  va_start (args, format);
   vfprintf (stderr, format, args);
   fprintf (stderr, "\n");
 
@@ -162,15 +156,12 @@
 }
 
 void
-fatal_error (va_alist)
-     va_dcl
+fatal_error (char *format, ...)
 {
   va_list args;
-  char *format;
 
   fprintf (stderr, "%s: ", get_name_for_error ());
-  va_start (args);
-  format = va_arg (args, char *);
+  va_start (args, format);
   vfprintf (stderr, format, args);
   fprintf (stderr, "\n");
 
@@ -179,14 +170,12 @@
 }
 
 void
-internal_error (va_alist)
-     va_dcl
+internal_error (char *format, ...)
 {
   va_list args;
-  char *format;
 
   fprintf (stderr, "%s: ", get_name_for_error ());
-  va_start (args);
+  va_start (args, format);
   format = va_arg (args, char *);
   vfprintf (stderr, format, args);
   fprintf (stderr, "\n");
@@ -194,14 +183,12 @@
   va_end (args);
 }
 
-itrace (va_alist)
-     va_dcl
+itrace (char *format, ...)
 {
   va_list args;
-  char *format;
 
   fprintf(stderr, "TRACE: pid %d: ", getpid());
-  va_start (args);
+  va_start (args, format);
   format = va_arg (args, char *);
   vfprintf (stderr, format, args);
   fprintf (stderr, "\n");
