--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2024-03-22 08:19:40 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -42,7 +42,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
