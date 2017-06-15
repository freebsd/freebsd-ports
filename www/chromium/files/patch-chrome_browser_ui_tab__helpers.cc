--- chrome/browser/ui/tab_helpers.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -245,7 +245,7 @@ void TabHelpers::AttachTabHelpers(WebCon
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 // --- Feature tab helpers behind flags ---
