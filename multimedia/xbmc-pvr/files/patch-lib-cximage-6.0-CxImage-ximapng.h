--- lib/cximage-6.0/CxImage/ximapng.h.orig	2012-03-16 00:33:05.000000000 +0100
+++ lib/cximage-6.0/CxImage/ximapng.h	2012-04-28 06:17:43.000000000 +0200
@@ -25,6 +25,7 @@
 #ifdef _LINUX
 #undef _DLL
 #include <png.h>
+#include <pngpriv.h>
 #else
 #include "../png/png.h"
 #endif
@@ -70,7 +71,7 @@
     static void PNGAPI user_error_fn(png_structp png_ptr,png_const_charp error_msg)
 	{
 		strncpy((char*)png_ptr->error_ptr,error_msg,255);
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 };
 
