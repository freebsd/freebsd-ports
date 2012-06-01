--- source/Irrlicht/CImageLoaderPNG.cpp.orig	2012-05-26 13:57:05.000000000 +0200
+++ source/Irrlicht/CImageLoaderPNG.cpp	2012-05-26 13:58:05.000000000 +0200
@@ -12,6 +12,7 @@
 	#else // _IRR_USE_NON_SYSTEM_LIB_PNG_
 	#include "libpng/png.h" // use irrlicht included lib png
 	#endif // _IRR_USE_NON_SYSTEM_LIB_PNG_
+	#include <pngpriv.h>
 #endif // _IRR_COMPILE_WITH_LIBPNG_
 
 #include "CImage.h"
@@ -28,7 +29,7 @@
 static void png_cpexcept_error(png_structp png_ptr, png_const_charp msg)
 {
 	os::Printer::log("PNG FATAL ERROR", msg, ELL_ERROR);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 
 // PNG function for file reading
@@ -162,7 +163,7 @@
 	if (BitDepth < 8)
 	{
 		if (ColorType==PNG_COLOR_TYPE_GRAY || ColorType==PNG_COLOR_TYPE_GRAY_ALPHA)
-			png_set_gray_1_2_4_to_8(png_ptr);
+			png_set_expand_gray_1_2_4_to_8(png_ptr);
 		else
 			png_set_packing(png_ptr);
 	}
