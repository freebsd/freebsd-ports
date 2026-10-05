--- submodules/microtex/platform/cairo/graphic_cairo.cpp.orig	2026-10-05 08:04:46 UTC
+++ submodules/microtex/platform/cairo/graphic_cairo.cpp
@@ -5,6 +5,8 @@
 
 #include <utility>
 
+#include <fontconfig/fcfreetype.h> // for FcFreeTypeQuery for fontconfig-2.18.3
+
 #include "graphic_cairo.h"
 #include "utils/log.h"
 #include "utils/utf.h"
