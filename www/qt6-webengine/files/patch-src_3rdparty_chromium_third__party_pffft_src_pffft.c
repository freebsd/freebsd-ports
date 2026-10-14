--- src/3rdparty/chromium/third_party/pffft/src/pffft.c.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/pffft/src/pffft.c
@@ -100,6 +100,7 @@
    Altivec support macros 
 */
 #if !defined(PFFFT_SIMD_DISABLE) && (defined(__ppc__) || defined(__ppc64__))
+#include <altivec.h>
 typedef vector float v4sf;
 #  define SIMD_SZ 4
 #  define VZERO() ((vector float) vec_splat_u8(0))
