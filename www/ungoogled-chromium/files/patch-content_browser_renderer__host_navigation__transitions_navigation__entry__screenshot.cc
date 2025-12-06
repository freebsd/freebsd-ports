--- content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc.orig	2025-12-06 13:30:52 UTC
+++ content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc
@@ -28,7 +28,7 @@
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "ui/gfx/skia_span_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 
 #ifndef MADV_POPULATE_WRITE
@@ -73,7 +73,7 @@ void CompressNavigationScreenshotOnWorkerThread(
 #endif  // BUILDFLAG(IS_ANDROID)
 
 void AdviseBitmap(SkBitmap& bitmap) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   size_t size = bitmap.info().computeByteSize(bitmap.info().minRowBytes());
   if (madvise(bitmap.getPixels(), size, MADV_POPULATE_WRITE) == 0) {
     return;
