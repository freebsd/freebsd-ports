--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2024-04-19 13:02:56 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -37,7 +37,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
