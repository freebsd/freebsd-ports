--- skia/ext/skcolorspace_trfn.cc.orig	2024-08-27 06:28:16 UTC
+++ skia/ext/skcolorspace_trfn.cc
@@ -7,6 +7,8 @@
 #pragma allow_unsafe_buffers
 #endif
 
+#include <cmath>
+
 #include "skia/ext/skcolorspace_trfn.h"
 
 #include <cmath>
