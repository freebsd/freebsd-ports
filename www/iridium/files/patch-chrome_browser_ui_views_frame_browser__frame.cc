--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -37,7 +37,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
@@ -48,7 +48,7 @@
 namespace {
 
 bool IsUsingGtkTheme(Profile* profile) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
@@ -104,7 +104,7 @@ void BrowserFrame::InitBrowserFrame() {
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
