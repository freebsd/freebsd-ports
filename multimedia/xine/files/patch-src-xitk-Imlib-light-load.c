--- src/xitk/Imlib-light/load.c.orig	2003-07-15 00:44:10.000000000 +0200
+++ src/xitk/Imlib-light/load.c	2010-03-29 10:16:04.000000000 +0200
@@ -193,7 +193,7 @@
     return 0;
   fread(buf, 1, 8, f);
   rewind(f);
-  return (int)png_check_sig(buf, 8);
+  return (int)(png_sig_cmp(buf, 0, 8) == 0);
 }
 
 ImlibImage * Imlib_load_image(ImlibData * id, char *file) {
