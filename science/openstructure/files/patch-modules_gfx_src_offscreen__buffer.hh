--- modules/gfx/src/offscreen_buffer.hh.orig	2018-07-09 00:19:53 UTC
+++ modules/gfx/src/offscreen_buffer.hh
@@ -58,7 +58,7 @@ public:
    bool IsValid();
 */
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #if OST_MESA_SUPPORT_ENABLED
 #include "impl/mesa_offscreen_buffer.hh"
 #else
