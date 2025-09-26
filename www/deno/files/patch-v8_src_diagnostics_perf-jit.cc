--- cargo-crates/v8-137.2.1/v8/src/diagnostics/perf-jit.cc.orig
+++ cargo-crates/v8-137.2.1/v8/src/diagnostics/perf-jit.cc
@@ -30,8 +30,7 @@
 #include "src/common/assert-scope.h"
 #include "src/flags/flags.h"
 
-// Only compile the {PerfJitLogger} on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if 1
 
 #include <fcntl.h>
 #include <sys/mman.h>
