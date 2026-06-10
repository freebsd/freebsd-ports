--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -62,7 +62,7 @@ const char* const kWebUIBrowserWindowKey = "__WEBUI_BR
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
