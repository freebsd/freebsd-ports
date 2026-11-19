--- chrome/browser/ui/views/frame/browser_widget.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/frame/browser_widget.cc
@@ -51,7 +51,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -88,7 +88,7 @@ class ThemeChangedObserver : public views::WidgetObser
 };
 
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -166,7 +166,7 @@ void BrowserWidget::InitBrowserWidget() {
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.startup_id =
       BrowserInitState::From(browser)->create_params().startup_id;
 #endif
@@ -218,7 +218,7 @@ void BrowserWidget::InitBrowserWidget() {
 
   Init(std::move(params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SelectNativeTheme();
 #else
   SetNativeTheme(ui::NativeTheme::GetInstanceForNativeUi());
@@ -528,7 +528,7 @@ void BrowserWidget::OnMenuClosed() {
 }
 
 void BrowserWidget::SelectNativeTheme() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the regular NativeTheme instance if running incognito mode or
   // enterprise isolated mode, regardless of system theme (gtk, qt etc).
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
@@ -569,7 +569,7 @@ void BrowserWidget::OnTouchUiChanged() {
 bool BrowserWidget::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
