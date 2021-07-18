--- base/allocator/partition_allocator/address_pool_manager.cc.orig	2021-04-14 18:40:48 UTC
+++ base/allocator/partition_allocator/address_pool_manager.cc
@@ -8,6 +8,13 @@
 #include <sys/mman.h>
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/mman.h>
+#include <fcntl.h>
+
+#include "base/posix/eintr_wrapper.h"
+#endif
+
 #include <algorithm>
 #include <limits>
 
@@ -50,6 +57,14 @@ void DecommitPages(void* address, size_t size) {
   void* ptr = mmap(address, size, PROT_NONE,
                    MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
   PA_CHECK(ptr == address);
+#elif defined(OS_FREEBSD)
+  int fd = HANDLE_EINTR(open("/dev/zero", O_RDONLY));
+  PA_CHECK(fd != -1);
+
+  void *ptr = mmap(address, size, PROT_NONE,
+                   MAP_FIXED | MAP_PRIVATE, fd, 0);
+  PA_PCHECK(ptr == address);
+  HANDLE_EINTR(close(fd));
 #else
   DecommitSystemPages(address, size, PageUpdatePermissions);
 #endif
