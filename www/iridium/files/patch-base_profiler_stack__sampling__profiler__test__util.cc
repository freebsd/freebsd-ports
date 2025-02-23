--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2025-02-22 18:06:53 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -46,7 +46,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
