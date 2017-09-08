--- base/debug/stack_trace.h.orig	2017-08-02 19:09:58.400190000 +0200
+++ base/debug/stack_trace.h	2017-08-02 19:10:33.950334000 +0200
@@ -16,6 +16,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_POSIX)
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
