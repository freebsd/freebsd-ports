--- src/_png.cpp.orig	2010-10-12 18:14:42.000000000 +0200
+++ src/_png.cpp	2012-05-06 06:33:48.000000000 +0200
@@ -20,6 +20,7 @@
 #   include "Python.h"
 
 #   include <png.h>
+#   include <pngpriv.h>
 #endif
 
 // TODO: Un CXX-ify this module
@@ -459,10 +460,10 @@
 
     //free the png memory
     png_read_end(png_ptr, info_ptr);
-#ifndef png_infopp_NULL
+#ifndef NULL
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 #else
-    png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 #endif
     if (close_file)
     {
