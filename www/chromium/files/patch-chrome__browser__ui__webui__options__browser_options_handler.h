--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2013-09-03 21:22:36.851628387 +0300
+++ chrome/browser/ui/webui/options/browser_options_handler.h	2013-09-03 21:23:09.395628553 +0300
@@ -193,7 +193,8 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
