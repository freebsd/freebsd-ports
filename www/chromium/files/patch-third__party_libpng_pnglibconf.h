--- third_party/libpng/pnglibconf.h.orig	2020-11-13 06:37:03 UTC
+++ third_party/libpng/pnglibconf.h
@@ -230,8 +230,11 @@
  * This is necessary to build multiple copies of libpng.  We need this while pdfium builds
  * its own copy of libpng.
  */
+/* Need to disable prefixing to unbundle chromium's libpng. */
+#if 0
 #define PNG_PREFIX
 #include "pngprefix.h"
+#endif
 /* end of chromium prefixing */
 
 #endif /* PNGLCONF_H */
