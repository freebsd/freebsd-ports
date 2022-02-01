--- chrome/test/chromedriver/chrome_launcher.cc.orig	2021-12-14 11:45:00 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -73,6 +73,10 @@
 #include <windows.h>
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
