--- chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_watch_apitest.cc.orig	2021-09-14 01:51:49 UTC
+++ chrome/browser/apps/platform_apps/api/media_galleries/media_galleries_watch_apitest.cc
@@ -242,7 +242,7 @@ IN_PROC_BROWSER_TEST_F(MediaGalleriesGalleryWatchApiTe
 // Test is flaky on windows and linux: crbug.com/1150017.
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #define MAYBE_RemoveListenerAndModifyGallery \
   DISABLED_RemoveListenerAndModifyGallery
 #else
