--- src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/allocator/allocator_shim_unittest.cc
@@ -4,7 +4,6 @@
 
 #include "base/allocator/allocator_shim.h"
 
-#include <malloc.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -193,11 +192,13 @@ TEST_F(AllocatorShimTest, InterceptLibcS
   ASSERT_GE(zero_allocs_intercepted_by_size[2 * 23], 1u);
 
 #if !defined(OS_WIN)
+#if !defined(OS_BSD)
   void* memalign_ptr = memalign(128, 53);
   ASSERT_NE(nullptr, memalign_ptr);
   ASSERT_EQ(0u, reinterpret_cast<uintptr_t>(memalign_ptr) % 128);
   ASSERT_GE(aligned_allocs_intercepted_by_alignment[128], 1u);
   ASSERT_GE(aligned_allocs_intercepted_by_size[53], 1u);
+#endif
 
   void* posix_memalign_ptr = nullptr;
   int res = posix_memalign(&posix_memalign_ptr, 256, 59);
@@ -214,12 +215,14 @@ TEST_F(AllocatorShimTest, InterceptLibcS
   ASSERT_GE(aligned_allocs_intercepted_by_alignment[kPageSize], 1u);
   ASSERT_GE(aligned_allocs_intercepted_by_size[61], 1u);
 
+#if !defined(OS_BSD)
   void* pvalloc_ptr = pvalloc(67);
   ASSERT_NE(nullptr, pvalloc_ptr);
   ASSERT_EQ(0u, reinterpret_cast<uintptr_t>(pvalloc_ptr) % kPageSize);
   ASSERT_GE(aligned_allocs_intercepted_by_alignment[kPageSize], 1u);
   // pvalloc rounds the size up to the next page.
   ASSERT_GE(aligned_allocs_intercepted_by_size[kPageSize], 1u);
+#endif
 #endif  // OS_WIN
 
   char* realloc_ptr = static_cast<char*>(realloc(nullptr, 71));
@@ -240,8 +243,10 @@ TEST_F(AllocatorShimTest, InterceptLibcS
   ASSERT_GE(frees_intercepted_by_addr[Hash(zero_alloc_ptr)], 1u);
 
 #if !defined(OS_WIN)
+#if !defined(OS_BSD)
   free(memalign_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(memalign_ptr)], 1u);
+#endif
 
   free(posix_memalign_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(posix_memalign_ptr)], 1u);
@@ -249,8 +254,10 @@ TEST_F(AllocatorShimTest, InterceptLibcS
   free(valloc_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(valloc_ptr)], 1u);
 
+#if !defined(OS_BSD)
   free(pvalloc_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(pvalloc_ptr)], 1u);
+#endif
 #endif  // OS_WIN
 
   free(realloc_ptr);
