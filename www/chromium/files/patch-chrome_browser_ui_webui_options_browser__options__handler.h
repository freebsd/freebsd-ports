--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -210,7 +210,7 @@ class BrowserOptionsHandler
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
