--- ./base/test/launcher/test_launcher.cc.orig	2014-08-20 21:02:41.000000000 +0200
+++ ./base/test/launcher/test_launcher.cc	2014-08-22 15:06:24.000000000 +0200
@@ -41,6 +41,10 @@
 #include "base/mac/scoped_nsautorelease_pool.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // Launches a child process using |command_line|. If the child process is still
