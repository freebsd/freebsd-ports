--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -204,7 +204,8 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
