--- images/fl_png.cxx.orig	2007-04-16 16:48:06.000000000 +0200
+++ images/fl_png.cxx	2010-03-29 19:55:26.000000000 +0200
@@ -62,7 +62,7 @@
 #if !HAVE_LIBPNG
   return 0;
 #else
-  return png_check_sig((png_byte*)datas, (int)size)!=0;
+  return !png_sig_cmp((png_byte*)datas, 0, (int)size)!=0;
 #endif
 }
 
