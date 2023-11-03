--- base/test/launcher/test_launcher.cc.orig	2023-11-03 10:09:45 UTC
+++ base/test/launcher/test_launcher.cc
@@ -70,6 +70,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
