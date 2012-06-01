--- src/images/Fl_Png.cpp.orig	2009-04-22 13:51:33.000000000 +0200
+++ src/images/Fl_Png.cpp	2012-05-06 21:06:13.000000000 +0200
@@ -3,6 +3,7 @@
 #if HAVE_PNG
 
 #include <png.h>
+#include <pngpriv.h>
 #include <stdlib.h>
 
 #include <efltk/Fl_Image.h>
@@ -28,7 +29,7 @@
     png_last_error = (volatile char*)"PNG: Unknown (ERROR!)";
     if (png_ptr != NULL && png_ptr->error_ptr != NULL)
         png_last_error = (volatile char*)message;
-    longjmp(png_ptr->jmpbuf, 0);
+    longjmp(png_jmpbuf(png_ptr), 0);
 }
 
 static bool png_is_valid_file(const char *filename)
@@ -81,7 +82,7 @@
     if(!end_info_ptr) { return_error(); }
 
     png_bytepp rows = 0;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(rows) free(rows);
         if(png_ptr) png_destroy_read_struct (&png_ptr, &info_ptr, &end_info_ptr);
         fputs((const char *)png_last_error, stderr);
@@ -318,7 +319,7 @@
 
     bool allocated = false;
     uint8 *wr_data = (uint8*)data;
-    if(setjmp(png_ptr->jmpbuf)) {
+    if(setjmp(png_jmpbuf(png_ptr))) {
         if(png_ptr) png_destroy_write_struct(&png_ptr, &info_ptr);
         if(allocated && wr_data) free(wr_data);
         return false;
