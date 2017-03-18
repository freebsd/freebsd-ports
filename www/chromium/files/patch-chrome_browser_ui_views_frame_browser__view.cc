--- chrome/browser/ui/views/frame/browser_view.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -179,7 +179,7 @@
 #include "chrome/browser/ui/views/sync/one_click_signin_dialog_view.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #endif
 
 using base::TimeDelta;
