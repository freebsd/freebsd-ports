Index: src/3rdparty/PhysX/include/extensions/PxDefaultAllocator.h
--- src/3rdparty/PhysX/include/extensions/PxDefaultAllocator.h.orig	2023-09-24 11:12:43 UTC
+++ src/3rdparty/PhysX/include/extensions/PxDefaultAllocator.h
@@ -41,8 +41,10 @@
 #include <stdlib.h>
 
 #if PX_WINDOWS_FAMILY || PX_LINUX_FAMILY || PX_SWITCH
+#if !PX_FREEBSD
 #include <malloc.h>
 #endif
+#endif
 
 #if !PX_DOXYGEN
 namespace physx
@@ -60,7 +62,7 @@ PX_FORCE_INLINE void platformAlignedFree(void* ptr)
 {
 	_aligned_free(ptr);
 }
-#elif PX_LINUX_FAMILY || PX_SWITCH
+#elif PX_LINUX_FAMILY && !PX_FREEBSD || PX_SWITCH
 PX_FORCE_INLINE void* platformAlignedAlloc(size_t size)
 {
 	return ::memalign(16, size);
