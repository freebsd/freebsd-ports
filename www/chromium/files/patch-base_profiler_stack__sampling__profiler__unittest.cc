--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2024-05-21 18:07:39 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -43,7 +43,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
