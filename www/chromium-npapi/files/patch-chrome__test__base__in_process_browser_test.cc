--- ./chrome/test/base/in_process_browser_test.cc.orig	2014-04-30 22:42:44.000000000 +0200
+++ ./chrome/test/base/in_process_browser_test.cc	2014-05-04 14:38:46.000000000 +0200
@@ -72,6 +72,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
