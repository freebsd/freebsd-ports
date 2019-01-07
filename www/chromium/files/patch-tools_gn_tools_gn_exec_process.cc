--- tools/gn/tools/gn/exec_process.cc.orig	2018-12-12 23:06:54.000000000 +0100
+++ tools/gn/tools/gn/exec_process.cc	2018-12-15 22:04:21.665099000 +0100
@@ -28,6 +28,10 @@
 #include "base/posix/file_descriptor_shuffle.h"
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace internal {
 
 #if defined(OS_WIN)
