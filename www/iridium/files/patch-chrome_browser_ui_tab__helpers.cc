--- chrome/browser/ui/tab_helpers.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -258,7 +258,7 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
