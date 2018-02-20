--- base/test/launcher/test_launcher.cc.orig	2017-12-15 02:04:05.000000000 +0100
+++ base/test/launcher/test_launcher.cc	2017-12-30 02:02:22.630578000 +0100
@@ -51,6 +51,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
