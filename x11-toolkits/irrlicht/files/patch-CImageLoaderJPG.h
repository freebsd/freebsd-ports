--- CImageLoaderJPG.h.orig	Sun Sep 19 00:48:11 2004
+++ CImageLoaderJPG.h	Sun Sep 19 00:53:05 2004
@@ -12,8 +12,8 @@
 #include "IrrCompileConfig.h"
 #ifdef _IRR_COMPILE_WITH_LIBJPEG_
 extern "C" {
-#include "jpeglib/jconfig.h"
-#include "jpeglib/jpeglib.h"
+#include "jconfig.h"
+#include "jpeglib.h"
 }
 #endif
 
