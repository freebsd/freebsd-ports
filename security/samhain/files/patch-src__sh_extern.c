--- src/sh_extern.c.orig	Fri Apr  7 20:07:53 2006
+++ src/sh_extern.c	Mon May 22 08:18:29 2006
@@ -1067,9 +1067,11 @@
  */
 int sh_ext_add_default (const char * dummy)
 {
-  (void) dummy;
-  char * p = NULL;
+  char * p;
   int    i;
+  (void) dummy;
+
+  p = NULL;
 
   SL_ENTER(_("sh_ext_add_default"));
   if (dummy[0] == 'n' ||  dummy[0] == 'N' ||
