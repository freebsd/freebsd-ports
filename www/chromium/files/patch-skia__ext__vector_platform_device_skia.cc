--- skia/ext/vector_platform_device_skia.cc.orig	2012-01-18 11:11:53.000000000 +0200
+++ skia/ext/vector_platform_device_skia.cc	2012-01-29 19:42:26.000000000 +0200
@@ -88,7 +88,7 @@
   SkASSERT(false);
   return NULL;
 }
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 void VectorPlatformDeviceSkia::DrawToNativeContext(
     PlatformSurface surface, int x, int y, const PlatformRect* src_rect) {
   // Should never be called on Linux.
