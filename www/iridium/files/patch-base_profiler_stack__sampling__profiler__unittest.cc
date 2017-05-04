--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2017-04-19 19:06:28 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -33,7 +33,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
