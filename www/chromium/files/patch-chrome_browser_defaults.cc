--- chrome/browser/defaults.cc.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/defaults.cc
@@ -46,7 +46,7 @@ const bool kSyncAutoStarts = false;
 const bool kShowOtherBrowsersInAboutMemory = true;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
