--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -53,7 +53,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -68,7 +68,7 @@ namespace {
 constexpr double kTitlePaddingWidthFraction = 0.1;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // These values are used for Linux/GTK.
 constexpr int kIconTitleSpacing = 4;
 constexpr int kCaptionSpacing = 5;
@@ -98,7 +98,7 @@ class ThemeChangedObserver : public views::WidgetObser
 };
 
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -204,7 +204,7 @@ void BrowserFrame::InitBrowserFrame() {
 
   Init(std::move(params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SelectNativeTheme();
 #else
   SetNativeTheme(ui::NativeTheme::GetInstanceForNativeUi());
@@ -450,7 +450,7 @@ void BrowserFrame::OnNativeWidgetWorkspaceChanged() {
   chrome::SaveWindowWorkspace(browser_view_->browser(), GetWorkspace());
   chrome::SaveWindowVisibleOnAllWorkspaces(browser_view_->browser(),
                                            IsVisibleOnAllWorkspaces());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If the window was sent to a different workspace, prioritize it if
   // it was sent to the current workspace and deprioritize it
   // otherwise.  This is done by MoveBrowsersInWorkspaceToFront()
@@ -649,7 +649,7 @@ void BrowserFrame::OnMenuClosed() {
 }
 
 void BrowserFrame::SelectNativeTheme() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the regular NativeTheme instance if running incognito mode, regardless
   // of system theme (gtk, qt etc).
   ui::NativeTheme* native_theme = ui::NativeTheme::GetInstanceForNativeUi();
@@ -690,7 +690,7 @@ void BrowserFrame::OnTouchUiChanged() {
 bool BrowserFrame::RegenerateFrameOnThemeChange(
     BrowserThemeChangeType theme_change_type) {
   bool need_regenerate = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // System and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   need_regenerate = true;
