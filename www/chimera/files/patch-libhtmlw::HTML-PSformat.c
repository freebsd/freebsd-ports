--- libhtmlw/HTML-PSformat.c.orig	Sun May  4 17:08:32 1997
+++ libhtmlw/HTML-PSformat.c	Sun Nov 30 11:03:28 2003
@@ -41,7 +41,11 @@
  *              permission of John Bradley.
  */
 
+#if 0
 #include <varargs.h>
+#else
+#include <stdarg.h>
+#endif
 
 #include <stdio.h>
 #include <ctype.h>
@@ -204,9 +208,13 @@
 }
 #else /* not BROKEN_SOLARIS_COMPILER_STDARG */
 static int
+#if 0
 PSprintf (format, va_alist)
 char *format;
 va_dcl
+#else
+PSprintf (char *format, ...)
+#endif
 {
   int len;
   char *s;
@@ -222,7 +230,11 @@
     }
     PS_string = s;
   }
+#if 0
   va_start (args);
+#else
+  va_start (args, format);
+#endif
   len = vsprintf (PS_string + PS_len, format, args);
   /* this is a hack to make it work on systems were vsprintf(s,...)
    * returns s, instead of the len.
