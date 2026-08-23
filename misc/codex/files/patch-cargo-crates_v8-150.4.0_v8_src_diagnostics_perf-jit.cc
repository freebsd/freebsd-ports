--- cargo-crates/v8-150.4.0/v8/src/diagnostics/perf-jit.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/src/diagnostics/perf-jit.cc
@@ -31,7 +31,7 @@
 #include "src/flags/flags.h"
 
 // Only compile the {PerfJitLogger} on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
 
 #include <fcntl.h>
 #include <sys/mman.h>
