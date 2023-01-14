--- src/3rdparty/chromium/v8/src/diagnostics/perf-jit.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/v8/src/diagnostics/perf-jit.cc
@@ -30,7 +30,7 @@
 #include "src/common/assert-scope.h"
 
 // Only compile the {PerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
