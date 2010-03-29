--- images.c.orig	2004-04-13 02:46:24.000000000 +0200
+++ images.c	2010-03-29 12:55:47.000000000 +0200
@@ -854,7 +854,7 @@
 
   // Check that it really is a PNG file
   fread (sig, 1, 8, image);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     panda_error (panda_true, "PNG file was invalid");
 
   // Start decompressing
@@ -1411,7 +1411,7 @@
   
     // Check that it really is a PNG file
     fread (sig, 1, 8, image);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     panda_error (panda_true, "PNG file was invalid");
   
     // Start decompressing
