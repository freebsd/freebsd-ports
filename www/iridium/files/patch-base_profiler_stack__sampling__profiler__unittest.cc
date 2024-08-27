--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2024-08-27 06:28:16 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -45,7 +45,7 @@
 
 #include <intrin.h>
 #include <malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
