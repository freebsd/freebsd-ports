--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2020-05-13 18:40:16 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -43,7 +43,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
