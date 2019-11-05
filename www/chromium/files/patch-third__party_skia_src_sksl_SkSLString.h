--- third_party/skia/src/sksl/SkSLString.h.orig	2019-09-09 21:57:02 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -13,6 +13,8 @@
 #include <stdarg.h>
 #include <string>
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
