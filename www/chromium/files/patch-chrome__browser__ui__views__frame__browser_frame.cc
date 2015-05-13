--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2015-04-18 23:43:03.000000000 +0200
+++ chrome/browser/ui/views/frame/browser_frame.cc	2015-04-18 23:46:33.000000000 +0200
@@ -33,7 +33,7 @@
 #include "ash/shell.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
@@ -82,7 +82,7 @@
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
