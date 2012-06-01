--- source/Irrlicht/CImageWriterPNG.cpp.orig	2012-05-26 13:57:05.000000000 +0200
+++ source/Irrlicht/CImageWriterPNG.cpp	2012-05-26 14:39:25.000000000 +0200
@@ -15,6 +15,7 @@
 #ifdef _IRR_COMPILE_WITH_LIBPNG_
 #ifndef _IRR_USE_NON_SYSTEM_LIB_PNG_
 	#include <png.h> // use system lib png
+	#include <pngpriv.h>
 #else // _IRR_USE_NON_SYSTEM_LIB_PNG_
 	#include "libpng/png.h" // use irrlicht included lib png
 #endif // _IRR_USE_NON_SYSTEM_LIB_PNG_
@@ -35,7 +36,7 @@
 static void png_cpexcept_error(png_structp png_ptr, png_const_charp msg)
 {
 	os::Printer::log("PNG FATAL ERROR", msg, ELL_ERROR);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 // PNG function for file writing
