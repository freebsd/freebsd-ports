--- chrome/browser/chrome_browser_main.cc.orig	2018-03-20 23:05:16.000000000 +0100
+++ chrome/browser/chrome_browser_main.cc	2018-03-24 22:37:46.110352000 +0100
@@ -206,7 +206,7 @@
 #include "chromeos/settings/cros_settings_names.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -244,7 +244,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #endif
 
@@ -737,7 +737,7 @@
   field_trial_synchronizer_ = new FieldTrialSynchronizer();
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
   metrics::DesktopSessionDurationTracker::Initialize();
 #endif
   metrics::RendererUptimeTracker::Initialize();
@@ -1145,7 +1145,7 @@
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
   // Set the product channel for crash reports.
   breakpad::SetChannelCrashKey(chrome::GetChannelString());
 #endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
@@ -1351,7 +1351,7 @@
 
 // Start the tab manager here so that we give the most amount of time for the
 // other services to start up before we start adjusting the oom priority.
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   g_browser_process->GetTabManager()->Start();
 #endif
 
