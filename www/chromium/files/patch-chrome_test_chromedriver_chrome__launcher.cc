--- chrome/test/chromedriver/chrome_launcher.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -70,6 +70,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
