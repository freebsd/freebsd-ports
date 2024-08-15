--- gfx/skia/skia/src/base/SkEndian.h.orig	2023-06-16 01:32:16.999830000 +0200
+++ gfx/skia/skia/src/base/SkEndian.h	2023-06-16 01:32:41.701673000 +0200
@@ -131,7 +131,7 @@
     #define SkTEndian_SwapLE64(n)    (n)
 #else   // SK_CPU_BENDIAN
     #define SkEndian_SwapBE16(n)    (n)
-    #define SkEndian_SwapBE32(n)    (n)
+    #define SkEndian_SwapBE32(n)    uint32_t(n)
     #define SkEndian_SwapBE64(n)    (n)
     #define SkEndian_SwapLE16(n)    SkEndianSwap16(n)
     #define SkEndian_SwapLE32(n)    SkEndianSwap32(n)
