--- chrome/browser/prefs/browser_prefs.cc.orig	2017-09-08 16:00:21.925956000 +0200
+++ chrome/browser/prefs/browser_prefs.cc	2017-09-08 16:04:23.999468000 +0200
@@ -262,7 +262,7 @@
 #include "chrome/browser/ui/desktop_ios_promotion/desktop_ios_promotion_util.h"
 #endif
 
-#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
+#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "chrome/browser/feature_engagement_tracker/new_tab/new_tab_tracker.h"
 #endif
 
@@ -586,7 +586,7 @@
   default_apps::RegisterProfilePrefs(registry);
 #endif
 
-#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
+#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && !defined(OS_BSD)
   feature_engagement_tracker::NewTabTracker::RegisterProfilePrefs(registry);
 #endif
 
