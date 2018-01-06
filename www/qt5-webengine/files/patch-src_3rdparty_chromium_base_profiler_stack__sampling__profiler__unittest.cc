--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc
@@ -31,7 +31,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
