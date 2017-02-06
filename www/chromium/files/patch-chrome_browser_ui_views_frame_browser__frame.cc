--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -37,11 +37,11 @@
 #include "ash/common/wm_shell.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/widget/desktop_aura/x11_desktop_handler.h"
 #endif
 
@@ -98,7 +98,7 @@ void BrowserFrame::InitBrowserFrame() {
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
