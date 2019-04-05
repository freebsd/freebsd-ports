--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_unittest.cc
@@ -39,7 +39,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
