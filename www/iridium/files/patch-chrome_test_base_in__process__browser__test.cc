--- chrome/test/base/in_process_browser_test.cc.orig	2017-04-19 19:06:31 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -94,6 +94,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
