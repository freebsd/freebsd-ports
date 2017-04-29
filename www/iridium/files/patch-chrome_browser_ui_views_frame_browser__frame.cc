--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -36,11 +36,11 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/widget/desktop_aura/x11_desktop_handler.h"
 #endif
 
@@ -97,7 +97,7 @@ void BrowserFrame::InitBrowserFrame() {
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
