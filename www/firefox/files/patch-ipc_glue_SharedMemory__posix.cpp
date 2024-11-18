commit bdd68dbe8130dcddde28581939ac50542f0b07ad
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    FreeBSD does not have MAP_NORESERVE

diff --git ipc/glue/SharedMemory_posix.cpp ipc/glue/SharedMemory_posix.cpp
index 73aaff1246c2..5ba7624f584d 100644
--- ipc/glue/SharedMemory_posix.cpp
+++ ipc/glue/SharedMemory_posix.cpp
@@ -62,7 +62,11 @@ SharedMemory::Handle SharedMemory::CloneHandle(const Handle& aHandle) {
 
 void* SharedMemory::FindFreeAddressSpace(size_t size) {
   void* memory = mmap(nullptr, size, PROT_NONE,
+#ifdef __FreeBSD__
+                      MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
+#else
                       MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE, -1, 0);
+#endif
   if (memory == MAP_FAILED) {
     return nullptr;
   }
