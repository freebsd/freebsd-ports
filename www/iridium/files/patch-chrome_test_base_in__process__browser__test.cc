--- chrome/test/base/in_process_browser_test.cc.orig	2020-04-03 04:11:30 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -77,6 +77,10 @@
 #include "chrome/test/base/scoped_bundle_swizzler_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -104,7 +108,7 @@
 #include "ui/events/test/event_generator.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/test/test_desktop_screen_x11.h"
 #endif
 
@@ -253,7 +257,7 @@ void InProcessBrowserTest::SetUp() {
   // Cookies). Without this on Mac and Linux, many tests will hang waiting for a
   // user to approve KeyChain/kwallet access. On Windows this is not needed as
   // OS APIs never block.
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   OSCryptMocker::SetUp();
 #endif
 
@@ -308,7 +312,7 @@ void InProcessBrowserTest::TearDown() {
   com_initializer_.reset();
 #endif
   BrowserTestBase::TearDown();
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   OSCryptMocker::TearDown();
 #endif
 
