--- ./tools/TexturePacker/XBMCTex.cpp.orig	2010-10-17 19:04:21.000000000 +0200
+++ ./tools/TexturePacker/XBMCTex.cpp	2010-12-01 12:17:34.285107108 +0100
@@ -40,7 +40,11 @@
 #endif
 
 #ifdef _LINUX
+#if defined(__FreeBSD__)
+#include <lzo/lzo1x.h>
+#else /* !__FreeBSD__ */
 #include <lzo1x.h>
+#endif
 #else
 #include "../../xbmc/lib/liblzo/LZO1X.H"
 #endif
