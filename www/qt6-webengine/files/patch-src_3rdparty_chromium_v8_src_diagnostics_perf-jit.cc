--- src/3rdparty/chromium/v8/src/diagnostics/perf-jit.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/v8/src/diagnostics/perf-jit.cc
@@ -31,7 +31,7 @@
 #include "src/flags/flags.h"
 
 // Only compile the {LinuxPerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
