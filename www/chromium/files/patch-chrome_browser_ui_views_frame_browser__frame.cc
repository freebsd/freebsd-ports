--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2017-07-25 21:04:51.000000000 +0200
+++ chrome/browser/ui/views/frame/browser_frame.cc	2017-08-02 00:17:41.951632000 +0200
@@ -36,7 +36,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
@@ -97,7 +97,7 @@
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
