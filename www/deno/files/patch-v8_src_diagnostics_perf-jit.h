--- cargo-crates/v8-137.2.1/v8/src/diagnostics/perf-jit.h.orig
+++ cargo-crates/v8-137.2.1/v8/src/diagnostics/perf-jit.h
@@ -30,8 +30,7 @@
 
 #include "include/v8config.h"
 
-// {PerfJitLogger} is only implemented on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if 1
 
 #include "src/logging/log.h"
 
