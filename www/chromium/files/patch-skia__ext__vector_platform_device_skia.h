--- skia/ext/vector_platform_device_skia.h.orig	2012-01-18 11:11:53.000000000 +0200
+++ skia/ext/vector_platform_device_skia.h	2012-01-29 19:44:49.000000000 +0200
@@ -43,7 +43,7 @@
                                    int y,
                                    const CGRect* src_rect) OVERRIDE;
   virtual CGContextRef GetBitmapContext() OVERRIDE;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   virtual void DrawToNativeContext(PlatformSurface surface,
                                    int x,
                                    int y,
