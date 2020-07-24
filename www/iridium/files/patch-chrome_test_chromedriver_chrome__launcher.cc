--- chrome/test/chromedriver/chrome_launcher.cc.orig	2020-03-16 18:40:30 UTC
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
