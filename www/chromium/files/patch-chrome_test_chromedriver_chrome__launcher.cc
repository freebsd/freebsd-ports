--- chrome/test/chromedriver/chrome_launcher.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -69,6 +69,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
