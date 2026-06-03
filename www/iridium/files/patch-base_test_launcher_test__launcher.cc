--- base/test/launcher/test_launcher.cc.orig	2026-02-16 10:45:29 UTC
+++ base/test/launcher/test_launcher.cc
@@ -66,6 +66,7 @@
 #include "third_party/abseil-cpp/absl/container/flat_hash_set.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
