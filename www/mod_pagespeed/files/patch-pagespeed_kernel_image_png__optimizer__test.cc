--- pagespeed/kernel/image/png_optimizer_test.cc.orig	2017-10-06 21:33:57 UTC
+++ pagespeed/kernel/image/png_optimizer_test.cc
@@ -36,6 +36,7 @@ extern "C" {
 #else
 #include "third_party/libpng/src/png.h"
 #endif
+#include "zlib.h"
 }
 
 namespace {
