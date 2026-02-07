--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -58,7 +58,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
