--- src/3rdparty/chromium/third_party/skia/src/sksl/SkSLString.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/skia/src/sksl/SkSLString.h
@@ -17,6 +17,8 @@
 #include "include/core/SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
