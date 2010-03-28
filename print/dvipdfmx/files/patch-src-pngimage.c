--- src/pngimage.c.orig	2009-05-11 04:15:26.000000000 +0200
+++ src/pngimage.c	2010-03-28 19:46:33.000000000 +0200
@@ -148,7 +148,7 @@
   rewind (png_file);
   if (fread (sigbytes, 1, sizeof(sigbytes), png_file) !=
       sizeof(sigbytes) ||
-      (!png_check_sig (sigbytes, sizeof(sigbytes))))
+      (png_sig_cmp (sigbytes, 0, sizeof(sigbytes))))
     return 0;
   else
     return 1;
