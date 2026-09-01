--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -73,7 +73,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
