--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2024-06-17 12:56:06 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -42,7 +42,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
