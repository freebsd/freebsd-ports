--- src/3rdparty/chromium/third_party/skia/src/sksl/SkSLString.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/skia/src/sksl/SkSLString.h
@@ -22,6 +22,8 @@
     #include "SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
