--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2014-10-10 08:54:11 UTC
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -36,7 +36,7 @@
 #include "ui/views/controls/menu/menu_runner.h"
 #include "ui/views/widget/native_widget.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -110,7 +110,7 @@
 #endif
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS)  || defined(OS_BSD)
   // Set up a custom WM_CLASS for some sorts of window types. This allows
   // task switchers in X11 environments to distinguish between main browser
   // windows and e.g app windows.
