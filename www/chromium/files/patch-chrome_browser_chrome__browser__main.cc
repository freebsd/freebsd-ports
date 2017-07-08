--- chrome/browser/chrome_browser_main.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -183,7 +183,7 @@
 #include "chrome/browser/feedback/feedback_profile_observer.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -274,7 +274,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #endif
 
@@ -477,9 +477,9 @@ void RegisterComponentsForUpdate() {
 
 #if !defined(OS_ANDROID)
   RegisterPepperFlashComponent(cus);
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   RegisterWidevineCdmComponent(cus);
-#endif  // !defined(OS_CHROMEOS)
+#endif  // !defined(OS_CHROMEOS) && !defined(OS_BSD)
 #endif  // !defined(OS_ANDROID)
 
 #if !defined(DISABLE_NACL) && !defined(OS_ANDROID)
@@ -761,7 +761,7 @@ void ChromeBrowserMainParts::SetupFieldTrials() {
   field_trial_synchronizer_ = new FieldTrialSynchronizer();
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
   metrics::DesktopSessionDurationTracker::Initialize();
 #endif
   metrics::RendererUptimeTracker::Initialize();
@@ -1191,11 +1191,11 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
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
@@ -1374,7 +1374,7 @@ void ChromeBrowserMainParts::PreBrowserStart() {
 
 // Start the tab manager here so that we give the most amount of time for the
 // other services to start up before we start adjusting the oom priority.
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   g_browser_process->GetTabManager()->Start();
 #endif
 
