--- ./third_party/skia/include/core/SkPreConfig.h.orig	2010-12-16 02:12:24.000000000 +0100
+++ ./third_party/skia/include/core/SkPreConfig.h	2010-12-20 20:15:08.000000000 +0100
@@ -57,6 +57,8 @@
 #if !defined(SK_RESTRICT)
     #define SK_RESTRICT __restrict__
 #endif
+#undef SK_RESTRICT
+#define SK_RESTRICT
 
 //////////////////////////////////////////////////////////////////////
 
