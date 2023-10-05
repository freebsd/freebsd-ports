- replace the pthread_getattr_np function

--- OMCompiler/SimulationRuntime/c/meta/meta_modelica_segv.c.orig	2023-10-04 02:19:12 UTC
+++ OMCompiler/SimulationRuntime/c/meta/meta_modelica_segv.c
@@ -35,6 +35,10 @@
 /* for pthread_getattr_np */
 #endif
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 #include "meta_modelica.h"
 
 void* mmc_getStacktraceMessages_threadData(threadData_t *threadData)
@@ -192,7 +196,12 @@ static void* getStackBase() {
   size_t size = 0;
   pthread_attr_t sattr;
   pthread_attr_init(&sattr);
+#if defined(__FreeBSD__)
+  pthread_attr_init(&sattr);
+  pthread_attr_get_np(self, &sattr);
+#elif defined(OS_LINUX)
   pthread_getattr_np(self, &sattr);
+#endif
   assert(0==pthread_attr_getstack(&sattr, &stackBottom, &size));
   assert(stackBottom);
   pthread_attr_destroy(&sattr);
