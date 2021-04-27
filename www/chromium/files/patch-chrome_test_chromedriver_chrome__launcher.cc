--- chrome/test/chromedriver/chrome_launcher.cc.orig	2021-04-14 18:40:56 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -71,6 +71,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
