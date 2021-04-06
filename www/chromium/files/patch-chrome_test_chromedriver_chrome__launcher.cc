--- chrome/test/chromedriver/chrome_launcher.cc.orig	2021-03-12 23:57:20 UTC
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
