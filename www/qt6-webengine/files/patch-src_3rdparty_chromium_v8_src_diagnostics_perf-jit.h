--- src/3rdparty/chromium/v8/src/diagnostics/perf-jit.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {LinuxPerfJitLogger} is only implemented on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include "src/logging/log.h"
 
