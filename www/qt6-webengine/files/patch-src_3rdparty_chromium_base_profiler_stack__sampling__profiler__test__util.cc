--- src/3rdparty/chromium/base/profiler/stack_sampling_profiler_test_util.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/profiler/stack_sampling_profiler_test_util.cc
@@ -33,7 +33,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
