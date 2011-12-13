--- skia/ext/vector_platform_device_skia.h.orig	2011-11-01 10:42:37.000000000 +0200
+++ skia/ext/vector_platform_device_skia.h	2011-11-21 22:29:46.000000000 +0200
@@ -40,7 +40,7 @@
   virtual void DrawToNativeContext(CGContext* context, int x, int y,
                                    const CGRect* src_rect);
   virtual CGContextRef GetBitmapContext();
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   virtual void DrawToNativeContext(PlatformSurface surface, int x, int y,
                                    const PlatformRect* src_rect);
 #endif
