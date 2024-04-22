--- base/test/launcher/test_launcher.cc.orig	2024-02-03 15:42:55 UTC
+++ base/test/launcher/test_launcher.cc
@@ -69,6 +69,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
