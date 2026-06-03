--- cmrtlib/linux/share/cm_def_os.h.orig	2026-03-19 10:15:05 UTC
+++ cmrtlib/linux/share/cm_def_os.h
@@ -32,15 +32,15 @@
 #define Display unsigned int
 #endif
 
+#include <cstdlib>
 #include <cstring>
 #include "pthread.h"
-#include <malloc.h>
 
 
 ////////////////////////////////////////////////////////////////////////////////////
 // MS-specific defines/typedefs, which are absent under Linux but still used
 ////////////////////////////////////////////////////////////////////////////////////
-#define _aligned_malloc(size, alignment) memalign(alignment, size)
+#define _aligned_malloc(size, alignment) aligned_alloc(alignment, size)
 #define _aligned_free(ptr) free(ptr)
 typedef uint8_t BOOLEAN, *PBOOLEAN;
 ////////////////////////////////////////////////////////////////////////////////////
@@ -101,7 +101,7 @@ inline void * CM_ALIGNED_MALLOC(size_t size, size_t al
 
 inline void * CM_ALIGNED_MALLOC(size_t size, size_t alignment)
 {
-  return memalign(alignment, size);
+  return aligned_alloc(alignment, size);
 }
 
 inline void CM_ALIGNED_FREE(void * memory)
