--- chrome/test/base/chrome_test_launcher.cc.orig	2020-07-07 21:58:14 UTC
+++ chrome/test/base/chrome_test_launcher.cc
@@ -61,7 +61,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/first_run/scoped_relaunch_chrome_browser_override.h"
 #include "chrome/browser/upgrade_detector/installed_version_poller.h"
 #include "testing/gtest/include/gtest/gtest.h"
@@ -81,7 +81,7 @@ int ChromeTestSuiteRunner::RunTestSuite(int argc, char
   content::ContentTestSuiteBase::RegisterInProcessThreads();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   InstalledVersionPoller::ScopedDisableForTesting disable_polling(
       InstalledVersionPoller::MakeScopedDisableForTesting());
 #endif
@@ -231,7 +231,7 @@ int LaunchChromeTests(size_t parallel_jobs,
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Cause a test failure for any test that triggers an unexpected relaunch.
   // Tests that fail here should likely be restructured to put the "before
   // relaunch" code into a PRE_ test with its own
