--- builtins/common.c.orig	Fri Aug 29 12:14:26 2003
+++ builtins/common.c	Fri Aug 29 12:18:31 2003
@@ -20,7 +20,7 @@
 #include <sys/types.h>
 #include "../posixstat.h"
 #if defined (HAVE_VFPRINTF)
-#include <varargs.h>
+#include <stdarg.h>
 #endif /* VFPRINTF */
 
 #if defined (HAVE_STRING_H)
@@ -114,16 +114,14 @@
    shell. */
 #if defined (HAVE_VFPRINTF)
 void
-builtin_error (va_alist)
-     va_dcl
+builtin_error (char *format, ...)
 {
-  char *format;
   va_list args;
 
   if (this_command_name && *this_command_name)
     fprintf (stderr, "%s: ", this_command_name);
 
-  va_start (args);
+  va_start (args, format);
   format = va_arg (args, char *);
   vfprintf (stderr, format, args);
   va_end (args);
