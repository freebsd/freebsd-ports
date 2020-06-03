--- content/public/test/browser_test_base.cc.orig	2020-05-13 18:40:32 UTC
+++ content/public/test/browser_test_base.cc
@@ -73,7 +73,7 @@
 #include "ui/gl/gl_implementation.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/platform_window/common/platform_window_defaults.h"  // nogncheck
 #endif
 
@@ -99,6 +99,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
@@ -185,7 +189,7 @@ BrowserTestBase::BrowserTestBase()
          "a new browser test suite that runs on Android, please add it to "
          "//build/android/pylib/gtest/gtest_test_instance.py.";
   g_instance_already_created = true;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::test::EnableTestConfigForPlatformWindows();
 #endif
 
