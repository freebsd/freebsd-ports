--- src/argp/argp-help.c.orig	Tue Jan  2 22:36:35 2001
+++ src/argp/argp-help.c	Wed Dec 18 05:22:38 2002
@@ -50,7 +50,9 @@
 #include <string.h>
 #include <assert.h>
 #include <stdarg.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <ctype.h>
 
 
@@ -196,7 +198,7 @@
   { "header-col",     0, offsetof (struct uparams, header_col) },
   { "usage-indent",   0, offsetof (struct uparams, usage_indent) },
   { "rmargin",        0, offsetof (struct uparams, rmargin) },
-  { 0 }
+  { 0, 0, 0 }
 };
 
 /* Read user options from the environment, and fill in UPARAMS appropiately.  */
@@ -1114,7 +1116,7 @@
   int old_wm = __argp_fmtstream_wmargin (stream);
   /* PEST is a state block holding some of our variables that we'd like to
      share with helper functions.  */
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__FreeBSD__)
   struct pentry_state pest = { entry, stream, hhstate, 1, state };
 #else /* !__GNUC__ */
   /* Decent initializers are a GNU extension */
