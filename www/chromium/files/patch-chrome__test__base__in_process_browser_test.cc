--- ./chrome/test/base/in_process_browser_test.cc.orig	2014-08-20 21:01:48.000000000 +0200
+++ ./chrome/test/base/in_process_browser_test.cc	2014-08-22 15:06:25.000000000 +0200
@@ -72,6 +72,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
