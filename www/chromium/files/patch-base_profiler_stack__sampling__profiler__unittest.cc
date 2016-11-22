--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/profiler/stack_sampling_profiler_unittest.cc	2016-10-25 21:31:13.576230000 +0300
@@ -30,7 +30,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
