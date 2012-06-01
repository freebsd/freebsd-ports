--- utils/TkCximage/src/CxImage/ximapng.h.orig	2012-05-05 13:24:02.000000000 +0200
+++ utils/TkCximage/src/CxImage/ximapng.h	2012-05-07 06:43:30.000000000 +0200
@@ -23,6 +23,7 @@
 
 extern "C" {
 #include <png.h>
+#include <pngpriv.h>
 }
 
 class CxImagePNG: public CxImage
@@ -65,7 +66,7 @@
     static void PNGAPI user_error_fn(png_structp png_ptr,png_const_charp error_msg)
 	{
 		strncpy((char*)png_ptr->error_ptr,error_msg,255);
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 };
 
