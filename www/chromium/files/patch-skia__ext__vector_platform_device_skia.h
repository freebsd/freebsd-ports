--- skia/ext/vector_platform_device_skia.h.orig	2011-10-09 00:19:07.294915003 +0300
+++ skia/ext/vector_platform_device_skia.h	2011-10-09 00:20:01.103617064 +0300
@@ -40,7 +40,7 @@
   virtual void DrawToNativeContext(CGContext* context, int x, int y,
                                    const CGRect* src_rect);
   virtual CGContextRef GetBitmapContext();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   virtual void DrawToNativeContext(PlatformSurface surface, int x, int y,
                                    const PlatformRect* src_rect);
 #endif
