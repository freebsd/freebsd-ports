--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_test_util.cc.orig	2023-04-28 17:01:32 UTC
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_test_util.cc
@@ -36,7 +36,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
