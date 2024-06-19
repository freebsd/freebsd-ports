--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2024-05-21 18:07:39 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -58,7 +58,7 @@ void ChromeBrowserMainExtraPartsLinux::PostBrowserStar
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* const command_line = base::CommandLine::ForCurrentProcess();
   auto env = base::Environment::Create();
   std::string desktop_startup_id;
