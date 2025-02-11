commit 30b15661a86e10fef4854dcb22e1d6dd6456e680
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    FreeBSD does not have MAP_NORESERVE

diff --git ipc/glue/SharedMemoryPlatform_posix.cpp ipc/glue/SharedMemoryPlatform_posix.cpp
index 017a7d29c9a3..2e88eeb11c5c 100644
--- ipc/glue/SharedMemoryPlatform_posix.cpp
+++ ipc/glue/SharedMemoryPlatform_posix.cpp
@@ -448,7 +448,11 @@ bool Platform::Protect(char* aAddr, size_t aSize, Access aAccess) {
 
 void* Platform::FindFreeAddressSpace(size_t aSize) {
   void* memory = mmap(nullptr, aSize, PROT_NONE,
+#ifdef __FreeBSD__
+                      MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
+#else
                       MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE, -1, 0);
+#endif
   if (memory == MAP_FAILED) {
     return nullptr;
   }
