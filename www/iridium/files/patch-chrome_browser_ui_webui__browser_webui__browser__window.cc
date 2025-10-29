--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -42,7 +42,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_frame.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
