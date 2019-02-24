--- chrome/browser/chrome_browser_main.cc.orig	2019-02-06 23:06:37.000000000 +0100
+++ chrome/browser/chrome_browser_main.cc	2019-02-12 20:03:14.042579000 +0100
@@ -216,7 +216,7 @@
 #include "chromeos/settings/cros_settings_names.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -256,7 +256,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #endif
 
@@ -1059,7 +1059,7 @@
       AddFirstRunNewTabs(browser_creator_.get(), master_prefs_->new_tabs);
     }
 
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     // Create directory for user-level Native Messaging manifest files. This
     // makes it less likely that the directory will be created by third-party
     // software with incorrect owner or permission. See crbug.com/725513 .
@@ -1068,14 +1068,14 @@
                                  &user_native_messaging_dir));
     if (!base::PathExists(user_native_messaging_dir))
       base::CreateDirectory(user_native_messaging_dir);
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
   // Set the product channel for crash reports.
   breakpad::SetChannelCrashKey(chrome::GetChannelName());
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX)
 
 #if defined(OS_MACOSX)
   // Get the Keychain API to register for distributed notifications on the main
@@ -1099,7 +1099,7 @@
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
   metrics::DesktopSessionDurationTracker::Initialize();
 #endif
   metrics::RendererUptimeTracker::Initialize();
@@ -1279,6 +1279,7 @@
       base::TimeDelta::FromMinutes(1));
 
 #if !defined(OS_ANDROID)
+#if !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebUsb)) {
     web_usb_detector_.reset(new WebUsbDetector());
     BrowserThread::PostAfterStartupTask(
@@ -1287,6 +1288,7 @@
         base::BindOnce(&WebUsbDetector::Initialize,
                        base::Unretained(web_usb_detector_.get())));
   }
+#endif
   if (base::FeatureList::IsEnabled(features::kTabMetricsLogging)) {
     // Initialize the TabActivityWatcher to begin logging tab activity events.
     resource_coordinator::TabActivityWatcher::GetInstance();
