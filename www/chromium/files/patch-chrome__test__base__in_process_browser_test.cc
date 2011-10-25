--- chrome/test/base/in_process_browser_test.cc.orig	2011-09-14 00:41:45.000000000 +0300
+++ chrome/test/base/in_process_browser_test.cc	2011-09-14 00:46:15.000000000 +0300
@@ -41,6 +41,10 @@
 #include "net/test/test_server.h"
 #include "sandbox/src/dep.h"
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include "base/mac/mac_util.h"
 #include "base/system_monitor/system_monitor.h"
