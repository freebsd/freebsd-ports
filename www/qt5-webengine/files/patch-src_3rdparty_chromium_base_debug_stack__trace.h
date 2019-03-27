--- src/3rdparty/chromium/base/debug/stack_trace.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/debug/stack_trace.h
@@ -16,6 +16,7 @@
 #include "build/build_config.h"
 
 #if defined(OS_POSIX)
+#include <sys/stdint.h>
 #include <unistd.h>
 #endif
 
