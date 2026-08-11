--- modules/scicos/includes/scicos_base64.hxx.orig	2026-05-19 09:32:07 UTC
+++ modules/scicos/includes/scicos_base64.hxx
@@ -25,7 +25,7 @@
 #include <string>
 #include <string_view>
 #include <vector>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include "fast_float/fast_float.h"
 #endif
 #ifdef max
