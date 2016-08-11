--- chrome/test/base/in_process_browser_test.cc.orig	2016-05-11 19:02:17 UTC
+++ chrome/test/base/in_process_browser_test.cc
@@ -90,6 +90,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
