--- tools/gn/tools/gn/exec_process.cc.orig	2019-12-16 21:58:04 UTC
+++ tools/gn/tools/gn/exec_process.cc
@@ -30,6 +30,10 @@
 #include "base/posix/file_descriptor_shuffle.h"
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace internal {
 
 #if defined(OS_WIN)
