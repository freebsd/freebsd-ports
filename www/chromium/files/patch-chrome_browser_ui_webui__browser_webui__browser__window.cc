--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -22,7 +22,7 @@ namespace {
 
 // Copied from chrome/browser/ui/views/frame/browser_frame.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
