--- cef/libcef/browser/chrome/views/chrome_browser_widget.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/chrome/views/chrome_browser_widget.cc
@@ -65,7 +65,7 @@ void ChromeBrowserWidget::Initialized()
 
   // Based on BrowserWidget::InitBrowserWidget.
   // This is the first call that will trigger theme-related client callbacks.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calls ThemeChanged() or OnNativeThemeUpdated().
   SelectNativeTheme();
 #else
