--- base/test/launcher/test_launcher.cc.orig	2022-03-28 18:11:04 UTC
+++ base/test/launcher/test_launcher.cc
@@ -63,6 +63,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
