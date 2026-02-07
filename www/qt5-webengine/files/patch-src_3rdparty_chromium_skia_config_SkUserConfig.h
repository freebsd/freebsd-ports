--- src/3rdparty/chromium/skia/config/SkUserConfig.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/skia/config/SkUserConfig.h
@@ -90,11 +90,18 @@ SK_API void SkDebugf_FileLine(const char* file, int li
     __FILE__, __LINE__, #cond); } } while (false)
 
 #if !defined(ANDROID)   // On Android, we use the skia default settings.
+#if defined(SK_CPU_BENDIAN)
+#define SK_A32_SHIFT    0
+#define SK_R32_SHIFT    8
+#define SK_G32_SHIFT    16
+#define SK_B32_SHIFT    24
+#else
 #define SK_A32_SHIFT    24
 #define SK_R32_SHIFT    16
 #define SK_G32_SHIFT    8
 #define SK_B32_SHIFT    0
 #endif
+#endif
 
 #if defined(SK_BUILD_FOR_MAC)
 
@@ -107,17 +114,6 @@ SK_API void SkDebugf_FileLine(const char* file, int li
 // TODO: skia used to just use hairline, but has improved since then, so
 // we should revisit this choice...
 #define SK_USE_FREETYPE_EMBOLDEN
-
-#if defined(SK_BUILD_FOR_UNIX) && defined(SK_CPU_BENDIAN)
-// Above we set the order for ARGB channels in registers. I suspect that, on
-// big endian machines, you can keep this the same and everything will work.
-// The in-memory order will be different, of course, but as long as everything
-// is reading memory as words rather than bytes, it will all work. However, if
-// you find that colours are messed up I thought that I would leave a helpful
-// locator for you. Also see the comments in
-// base/gfx/bitmap_platform_device_linux.h
-#error Read the comment at this location
-#endif
 
 #endif
 
