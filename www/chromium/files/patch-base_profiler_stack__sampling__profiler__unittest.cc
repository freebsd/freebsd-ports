--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2019-03-11 22:00:51 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -39,7 +39,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
