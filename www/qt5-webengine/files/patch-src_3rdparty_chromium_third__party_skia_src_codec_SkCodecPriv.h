--- src/3rdparty/chromium/third_party/skia/src/codec/SkCodecPriv.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/codec/SkCodecPriv.h
@@ -14,6 +14,7 @@
 #include "SkEncodedOrigin.h"
 #include "SkImageInfo.h"
 #include "SkTypes.h"
+#include "SkEndian.h"
 
 #ifdef SK_PRINT_CODEC_MESSAGES
     #define SkCodecPrintf SkDebugf
