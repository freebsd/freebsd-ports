--- cef/libcef/browser/views/widget_impl.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/views/widget_impl.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -26,7 +26,7 @@ void CefWidgetImpl::Initialized() {
 
   // Based on BrowserWidget::InitBrowserFrame.
   // This is the first call that will trigger theme-related client callbacks.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calls ThemeChanged() or OnNativeThemeUpdated().
   SelectNativeTheme();
 #else
@@ -166,7 +166,7 @@ void CefWidgetImpl::NotifyThemeColorsCha
 
 void CefWidgetImpl::SelectNativeTheme() {
   // Based on BrowserWidget::SelectNativeTheme.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
 
   // Always use the NativeTheme for forced color modes.
