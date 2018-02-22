--- third_party/skia/src/sksl/SkSLString.h.orig	2017-12-24 19:10:48.599527000 +0100
+++ third_party/skia/src/sksl/SkSLString.h	2017-12-24 19:11:12.662001000 +0100
@@ -22,6 +22,8 @@
     #include "SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
