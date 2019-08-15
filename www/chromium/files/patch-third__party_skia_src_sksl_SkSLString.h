--- third_party/skia/src/sksl/SkSLString.h.orig	2019-07-24 19:03:37 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -22,6 +22,8 @@
     #include "include/core/SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
