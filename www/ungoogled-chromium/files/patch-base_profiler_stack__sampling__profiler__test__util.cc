--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2023-05-05 12:12:41 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -36,7 +36,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
