--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -28,7 +28,7 @@ void ChromeBrowserMainExtraPartsOzone::PostCreateMainM
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
