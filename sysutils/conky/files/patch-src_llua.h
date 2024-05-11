--- src/llua.h.orig	2024-05-07 20:02:47 UTC
+++ src/llua.h
@@ -31,6 +31,7 @@ extern "C" {
 }
 
 #include <config.h>
+#include "geometry.h"
 
 #ifdef BUILD_MOUSE_EVENTS
 #include "mouse-events.h"
