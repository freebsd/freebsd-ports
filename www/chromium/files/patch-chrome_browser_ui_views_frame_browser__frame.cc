--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -38,14 +38,14 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "ui/display/screen.h"
 #endif
 
 namespace {
 
 bool IsUsingGtkTheme(Profile* profile) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -218,7 +218,7 @@ const ui::NativeTheme* BrowserFrame::GetNativeTheme() 
 
 void BrowserFrame::OnNativeWidgetWorkspaceChanged() {
   chrome::SaveWindowWorkspace(browser_view_->browser(), GetWorkspace());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   auto workspace = display::Screen::GetScreen()->GetCurrentWorkspace();
   BrowserList::MoveBrowsersInWorkspaceToFront(workspace.empty() ? GetWorkspace()
                                                                 : workspace);
