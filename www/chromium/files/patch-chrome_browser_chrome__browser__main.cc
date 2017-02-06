--- chrome/browser/chrome_browser_main.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -181,7 +181,7 @@
 #include "chrome/browser/feedback/feedback_profile_observer.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -1194,11 +1194,11 @@ int ChromeBrowserMainParts::PreCreateThr
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set the product channel for crash reports.
   base::debug::SetCrashKeyValue(crash_keys::kChannel,
                                 chrome::GetChannelString());
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Initialize tracking synchronizer system.
   tracking_synchronizer_ = new metrics::TrackingSynchronizer(
