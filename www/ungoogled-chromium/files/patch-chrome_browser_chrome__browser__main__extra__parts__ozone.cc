--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2024-04-23 07:42:17 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -27,7 +27,7 @@ void ChromeBrowserMainExtraPartsOzone::PostCreateMainM
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Lacros's `PostMainMessageLoopRun` must be called at the very end of
   // `PostMainMessageLoopRun` in
   // `ChromeBrowserMainPartsLacros::PostMainMessageLoopRun`.
