--- skia/ext/vector_platform_device_skia.cc.orig	2011-11-01 10:42:37.000000000 +0200
+++ skia/ext/vector_platform_device_skia.cc	2011-11-21 22:28:09.000000000 +0200
@@ -88,7 +88,7 @@
   SkASSERT(false);
   return NULL;
 }
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 void VectorPlatformDeviceSkia::DrawToNativeContext(
     PlatformSurface surface, int x, int y, const PlatformRect* src_rect) {
   // Should never be called on Linux.
