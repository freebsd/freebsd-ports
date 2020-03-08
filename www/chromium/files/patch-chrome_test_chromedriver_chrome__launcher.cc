--- chrome/test/chromedriver/chrome_launcher.cc.orig	2020-03-03 18:53:53 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -68,6 +68,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
