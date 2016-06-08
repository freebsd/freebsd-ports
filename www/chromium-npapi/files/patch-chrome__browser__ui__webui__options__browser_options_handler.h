--- ./chrome/browser/ui/webui/options/browser_options_handler.h.orig	2014-04-30 22:42:10.000000000 +0200
+++ ./chrome/browser/ui/webui/options/browser_options_handler.h	2014-05-04 14:38:46.000000000 +0200
@@ -183,7 +183,8 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
