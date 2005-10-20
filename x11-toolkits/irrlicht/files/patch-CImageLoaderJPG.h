--- CImageLoaderJPG.h.orig	Wed Oct 19 17:24:14 2005
+++ CImageLoaderJPG.h	Wed Oct 19 17:26:32 2005
@@ -12,12 +12,13 @@
 #include "IrrCompileConfig.h"
 #ifdef _IRR_COMPILE_WITH_LIBJPEG_
 extern "C" {
-	#include "jpeglib/jconfig.h"
 	#ifndef _IRR_USE_NON_SYSTEM_JPEG_LIB_
+	#include <jconfig.h>
 	#include <jpeglib.h> // use system lib
 	#else  // _IRR_USE_NON_SYSTEM_JPEG_LIB_
+	#include "jpeglib/jconfig.h"
 	#include "jpeglib/jpeglib.h" // use irrlicht jpeglib
-#endif // _IRR_USE_NON_SYSTEM_JPEG_LIB_
+	#endif // _IRR_USE_NON_SYSTEM_JPEG_LIB_
 }
 #endif // _IRR_COMPILE_WITH_LIBJPEG_
 
