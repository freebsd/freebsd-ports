--- base/test/launcher/test_launcher.cc.orig	2024-01-30 07:53:34 UTC
+++ base/test/launcher/test_launcher.cc
@@ -69,6 +69,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
