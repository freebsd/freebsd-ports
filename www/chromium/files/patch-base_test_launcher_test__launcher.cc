--- base/test/launcher/test_launcher.cc.orig	2025-03-05 08:14:56 UTC
+++ base/test/launcher/test_launcher.cc
@@ -74,6 +74,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
