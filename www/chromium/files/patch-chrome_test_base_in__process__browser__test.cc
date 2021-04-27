--- chrome/test/base/in_process_browser_test.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -82,6 +82,10 @@
 #include "services/device/public/cpp/test/fake_geolocation_system_permission.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_WIN)
 #include "base/win/scoped_com_initializer.h"
 #include "base/win/windows_version.h"
@@ -332,7 +336,7 @@ void InProcessBrowserTest::SetUp() {
   // Cookies). Without this on Mac and Linux, many tests will hang waiting for a
   // user to approve KeyChain/kwallet access. On Windows this is not needed as
   // OS APIs never block.
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   OSCryptMocker::SetUp();
 #endif
 
@@ -395,7 +399,7 @@ void InProcessBrowserTest::TearDown() {
   com_initializer_.reset();
 #endif
   BrowserTestBase::TearDown();
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   OSCryptMocker::TearDown();
 #endif
 
