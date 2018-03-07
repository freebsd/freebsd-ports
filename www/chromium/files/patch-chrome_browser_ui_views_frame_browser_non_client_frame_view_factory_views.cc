--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2018-03-03 21:07:27.595112000 +0100
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc	2018-03-03 21:07:57.689186000 +0100
@@ -18,7 +18,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
