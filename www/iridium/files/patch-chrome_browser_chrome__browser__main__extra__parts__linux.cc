--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2025-06-19 07:37:57 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -60,7 +60,7 @@ void ChromeBrowserMainExtraPartsLinux::PostBrowserStar
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* const command_line =
       base::CommandLine::ForCurrentProcess();
   std::unique_ptr<base::Environment> env = base::Environment::Create();
