--- third_party/skia/src/sksl/SkSLString.h.orig	2021-03-13 00:03:41 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -17,6 +17,8 @@
 #include "include/core/SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 class String;
