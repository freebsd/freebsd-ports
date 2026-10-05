-- fontconfig 2.18.3 compatibility

--- src/platform/cairo/graphic_cairo.cpp.orig	2026-10-05 17:05:51 UTC
+++ src/platform/cairo/graphic_cairo.cpp
@@ -5,6 +5,7 @@
 #include "platform/cairo/graphic_cairo.h"
 
 #include <fontconfig/fontconfig.h>
+#include <fontconfig/fcfreetype.h>
 
 #include <utility>
 
