--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2022-10-01 07:40:07 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -39,7 +39,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
