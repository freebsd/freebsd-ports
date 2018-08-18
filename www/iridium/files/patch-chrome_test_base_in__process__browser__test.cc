--- chrome/test/base/in_process_browser_test.cc.orig	2017-06-05 19:03:04 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -95,6 +95,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
