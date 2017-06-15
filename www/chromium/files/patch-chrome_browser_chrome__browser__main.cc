--- chrome/browser/chrome_browser_main.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -181,7 +181,7 @@
 #include "chrome/browser/lifetime/application_lifetime.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -276,7 +276,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #endif
 
@@ -479,10 +479,10 @@ void RegisterComponentsForUpdate() {
 
 #if !defined(OS_ANDROID)
   RegisterPepperFlashComponent(cus);
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   RegisterSwiftShaderComponent(cus);
   RegisterWidevineCdmComponent(cus);
-#endif  // !defined(OS_CHROMEOS)
+#endif  // !defined(OS_CHROMEOS) && !defined(OS_BSD)
 #endif  // !defined(OS_ANDROID)
 
 #if !defined(DISABLE_NACL) && !defined(OS_ANDROID)
@@ -764,7 +764,7 @@ void ChromeBrowserMainParts::SetupFieldT
   field_trial_synchronizer_ = new FieldTrialSynchronizer();
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
   metrics::DesktopSessionDurationTracker::Initialize();
 #endif
 
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
@@ -1387,7 +1387,7 @@ void ChromeBrowserMainParts::PreBrowserS
 
 // Start the tab manager here so that we give the most amount of time for the
 // other services to start up before we start adjusting the oom priority.
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   g_browser_process->GetTabManager()->Start();
 #endif
 
