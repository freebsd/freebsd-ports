--- v8/src/diagnostics/perf-jit.cc.orig	2021-06-11 10:18:03 UTC
+++ v8/src/diagnostics/perf-jit.cc
@@ -30,7 +30,7 @@
 #include "src/common/assert-scope.h"
 
 // Only compile the {PerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
