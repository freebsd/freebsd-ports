--- libs/libmythui/mythrender_vdpau.h.orig	2018-01-27 11:25:49 UTC
+++ libs/libmythui/mythrender_vdpau.h
@@ -12,6 +12,7 @@
 
 extern "C" {
 #include "libavcodec/vdpau.h"
+#include <vdpau/vdpau_x11.h>
 }
 
 #define MIN_OUTPUT_SURFACES  2 // UI
