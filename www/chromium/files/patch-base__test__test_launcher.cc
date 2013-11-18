--- base/test/test_launcher.cc.orig	2013-11-08 07:42:08.000000000 +0100
+++ base/test/test_launcher.cc	2013-11-15 14:11:58.000000000 +0100
@@ -8,6 +8,10 @@
 #include <fcntl.h>
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 #include "base/at_exit.h"
 #include "base/bind.h"
 #include "base/command_line.h"
