--- tools/gn/tools/gn/exec_process.cc.orig	2019-03-11 22:12:13 UTC
+++ tools/gn/tools/gn/exec_process.cc
@@ -29,6 +29,10 @@
 #include "base/posix/file_descriptor_shuffle.h"
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 namespace internal {
 
 #if defined(OS_WIN)
