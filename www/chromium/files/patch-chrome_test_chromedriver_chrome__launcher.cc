--- chrome/test/chromedriver/chrome_launcher.cc.orig	2019-04-30 22:22:38 UTC
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -66,6 +66,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 // TODO(eseckler): Remove --ignore-certificate-errors for newer Chrome versions
