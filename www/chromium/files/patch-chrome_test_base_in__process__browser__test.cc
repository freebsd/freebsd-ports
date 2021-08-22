--- chrome/test/base/in_process_browser_test.cc.orig	2021-07-19 18:45:11 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -83,6 +83,10 @@
 #include "services/device/public/cpp/test/fake_geolocation_manager.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -334,7 +338,7 @@ void InProcessBrowserTest::SetUp() {
   // Cookies). Without this on Mac and Linux, many tests will hang waiting for a
   // user to approve KeyChain/kwallet access. On Windows this is not needed as
   // OS APIs never block.
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   OSCryptMocker::SetUp();
 #endif
 
@@ -403,7 +407,7 @@ void InProcessBrowserTest::TearDown() {
   com_initializer_.reset();
 #endif
   BrowserTestBase::TearDown();
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   OSCryptMocker::TearDown();
 #endif
 
