--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2024-05-11 05:39:22 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -175,7 +175,7 @@ void ChromeBrowserMainExtraPartsLinux::PostBrowserStar
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the desktop, we fix the platform name if necessary.
   // See https://crbug.com/1246928.
   auto* const command_line = base::CommandLine::ForCurrentProcess();
