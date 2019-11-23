--- src/3rdparty/chromium/third_party/skia/include/core/SkPostConfig.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/include/core/SkPostConfig.h
@@ -40,12 +40,6 @@
 #  error "must define either SK_CPU_LENDIAN or SK_CPU_BENDIAN"
 #endif
 
-#if defined(SK_CPU_BENDIAN) && !defined(I_ACKNOWLEDGE_SKIA_DOES_NOT_SUPPORT_BIG_ENDIAN)
-    #error "The Skia team is not endian-savvy enough to support big-endian CPUs."
-    #error "If you still want to use Skia,"
-    #error "please define I_ACKNOWLEDGE_SKIA_DOES_NOT_SUPPORT_BIG_ENDIAN."
-#endif
-
 /**
  * Ensure the port has defined all of SK_X32_SHIFT, or none of them.
  */
