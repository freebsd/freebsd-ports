--- chrome/browser/chrome_browser_main.cc.orig	2017-03-09 20:04:28 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -180,7 +180,7 @@
 #include "chrome/browser/lifetime/application_lifetime.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -1173,11 +1173,11 @@ int ChromeBrowserMainParts::PreCreateThr
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
