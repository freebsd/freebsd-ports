--- cmrtlib/linux/share/cm_rt_def_os.h.orig	2026-03-19 10:15:05 UTC
+++ cmrtlib/linux/share/cm_rt_def_os.h
@@ -36,7 +36,6 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <math.h>
-#include <malloc.h>
 #include <string.h>
 #include <sys/time.h>
 #include <pthread.h>
@@ -175,7 +174,7 @@ inline void * CM_ALIGNED_MALLOC(size_t size, size_t al
 
 inline void * CM_ALIGNED_MALLOC(size_t size, size_t alignment) 
 {
-  return memalign(alignment, size);
+  return aligned_alloc(alignment, size);
 } 
 
 inline void CM_ALIGNED_FREE(void * memory) 
