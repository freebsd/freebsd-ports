--- src/argp/argp-help.c.orig	Wed Feb  2 15:14:31 2000
+++ src/argp/argp-help.c	Tue Dec 17 13:08:02 2002
@@ -56,7 +56,9 @@
 #include <string.h>
 #include <assert.h>
 #include <stdarg.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <ctype.h>
 
 #ifndef _
@@ -182,7 +184,7 @@
   { "header-col",     0, offsetof (struct uparams, header_col) },
   { "usage-indent",   0, offsetof (struct uparams, usage_indent) },
   { "rmargin",        0, offsetof (struct uparams, rmargin) },
-  { 0 }
+  { 0, 0, 0 }
 };
 
 /* Read user options from the environment, and fill in UPARAMS appropiately.  */
