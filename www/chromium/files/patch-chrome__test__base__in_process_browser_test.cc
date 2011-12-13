--- chrome/test/base/in_process_browser_test.cc.orig	2011-11-01 10:43:07.000000000 +0200
+++ chrome/test/base/in_process_browser_test.cc	2011-11-19 19:32:51.000000000 +0200
@@ -41,6 +41,10 @@
 #include "chrome/browser/chromeos/audio_handler.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 static const char kBrowserTestType[] = "browser";
 
