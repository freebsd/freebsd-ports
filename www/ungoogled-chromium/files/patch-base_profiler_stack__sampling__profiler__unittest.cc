--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2024-03-22 14:16:19 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -42,7 +42,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
