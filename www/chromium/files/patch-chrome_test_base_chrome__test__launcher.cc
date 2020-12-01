--- chrome/test/base/chrome_test_launcher.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/test/base/chrome_test_launcher.cc
@@ -61,7 +61,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/first_run/scoped_relaunch_chrome_browser_override.h"
 #include "chrome/browser/upgrade_detector/installed_version_poller.h"
 #include "testing/gtest/include/gtest/gtest.h"
@@ -79,7 +79,7 @@ int ChromeTestSuiteRunner::RunTestSuite(int argc, char
   content::ContentTestSuiteBase::RegisterInProcessThreads();
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   InstalledVersionPoller::ScopedDisableForTesting disable_polling(
       InstalledVersionPoller::MakeScopedDisableForTesting());
 #endif
@@ -201,7 +201,7 @@ int LaunchChromeTests(size_t parallel_jobs,
   if (command_line.HasSwitch(switches::kLaunchAsBrowser))
     sampling_profiler = std::make_unique<MainThreadStackSamplingProfiler>();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   ChromeCrashReporterClient::Create();
 #elif defined(OS_WIN)
   // We leak this pointer intentionally. The crash client needs to outlive
@@ -229,7 +229,7 @@ int LaunchChromeTests(size_t parallel_jobs,
   }
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Cause a test failure for any test that triggers an unexpected relaunch.
   // Tests that fail here should likely be restructured to put the "before
   // relaunch" code into a PRE_ test with its own
