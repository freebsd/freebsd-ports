--- cargo-crates/v8-149.4.0/v8/src/diagnostics/perf-jit.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-149.4.0/v8/src/diagnostics/perf-jit.cc
@@ -30,8 +30,7 @@
 #include "src/common/assert-scope.h"
 #include "src/flags/flags.h"
 
-// Only compile the {PerfJitLogger} on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if 1
 
 #include <fcntl.h>
 #include <sys/mman.h>
