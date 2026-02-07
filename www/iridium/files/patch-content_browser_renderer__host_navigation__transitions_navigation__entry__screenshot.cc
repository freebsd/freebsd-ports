--- content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc.orig	2026-01-16 14:21:21 UTC
+++ content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc
@@ -71,7 +71,7 @@ void CompressNavigationScreenshotOnWorkerThread(
 }
 
 void AdviseBitmap(SkBitmap& bitmap) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   size_t size = bitmap.info().computeByteSize(bitmap.info().minRowBytes());
   if (madvise(bitmap.getPixels(), size, MADV_POPULATE_WRITE) == 0) {
     return;
