--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2020-07-13 13:09:53 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -23,7 +23,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
