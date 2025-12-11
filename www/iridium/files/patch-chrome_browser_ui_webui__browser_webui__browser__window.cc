--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -54,7 +54,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
