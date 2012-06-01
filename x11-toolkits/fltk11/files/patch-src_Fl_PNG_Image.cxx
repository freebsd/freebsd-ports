--- src/Fl_PNG_Image.cxx.orig	2006-06-09 18:16:34.000000000 +0200
+++ src/Fl_PNG_Image.cxx	2012-05-26 13:55:30.000000000 +0200
@@ -46,6 +46,7 @@
 #  include <zlib.h>
 #  ifdef HAVE_PNG_H
 #    include <png.h>
+#    include <pngpriv.h>
 #  else
 #    include <libpng/png.h>
 #  endif // HAVE_PNG_H
@@ -75,7 +76,7 @@
   pp   = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
   info = png_create_info_struct(pp);
 
-  if (setjmp(pp->jmpbuf))
+  if (setjmp(png_jmpbuf(pp)))
   {
     Fl::warning("PNG file \"%s\" contains errors!\n", png);
     return;
