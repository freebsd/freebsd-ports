--- chrome/browser/ui/views/frame/browser_widget.cc.orig	2026-10-18 13:29:39 UTC
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
@@ -167,7 +167,7 @@ void BrowserWidget::InitBrowserWidget() {
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.startup_id =
       BrowserInitState::From(browser)->create_params().startup_id;
 #endif
@@ -227,7 +227,7 @@ void BrowserWidget::InitBrowserWidget() {
                                 base::Unretained(this)));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SelectNativeTheme();
 #else
   SetNativeTheme(ui::NativeTheme::GetInstanceForNativeUi());
@@ -544,7 +544,7 @@ void BrowserWidget::OnMenuClosed() {
 }
 
 void BrowserWidget::SelectNativeTheme() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the regular NativeTheme instance if running incognito mode or
   // enterprise isolated mode, regardless of system theme (gtk, qt etc).
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
@@ -591,7 +591,7 @@ void BrowserWidget::OnGlassFrameEligibilityChanged(boo
 bool BrowserWidget::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
