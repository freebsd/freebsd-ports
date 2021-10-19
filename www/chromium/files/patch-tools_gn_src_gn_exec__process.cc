--- tools/gn/src/gn/exec_process.cc.orig	2021-09-24 04:34:58 UTC
+++ tools/gn/src/gn/exec_process.cc
@@ -31,6 +31,10 @@
 #include "base/posix/file_descriptor_shuffle.h"
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace internal {
 
 #if defined(OS_WIN)
