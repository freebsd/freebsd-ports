--- skia/ext/vector_platform_device_skia.cc.orig	2011-10-09 00:19:19.935845255 +0300
+++ skia/ext/vector_platform_device_skia.cc	2011-10-09 00:19:41.820724365 +0300
@@ -88,7 +88,7 @@
   SkASSERT(false);
   return NULL;
 }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 void VectorPlatformDeviceSkia::DrawToNativeContext(
     PlatformSurface surface, int x, int y, const PlatformRect* src_rect) {
   // Should never be called on Linux.
