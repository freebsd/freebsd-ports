-- FreeBSD is not Linux, but PaddlePaddle source defines _LINUX for any
-- platform that is not Windows or macOS (using '#if defined _WIN32 || defined
-- __APPLE__'). This causes Linux-only code (stdio_ext.h includes, glibc-specific
-- syscalls) to be compiled on FreeBSD. Add __FreeBSD__ to the exclusion list.
--- paddle/fluid/framework/data_set.cc.orig	2026-09-09 02:40:49 UTC
+++ paddle/fluid/framework/data_set.cc
@@ -26,7 +26,7 @@
 #include "paddle/phi/core/platform/monitor.h"
 #include "paddle/phi/core/platform/timer.h"
 
-#if defined _WIN32 || defined __APPLE__
+#if defined _WIN32 || defined __APPLE__ || defined __FreeBSD__
 #else
 #define _LINUX
 #endif
