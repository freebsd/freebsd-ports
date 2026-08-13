--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -72,7 +72,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
