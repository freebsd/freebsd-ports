--- base/allocator/allocator_shim_unittest.cc.orig	2017-06-05 19:03:00 UTC
+++ base/allocator/allocator_shim_unittest.cc
@@ -293,7 +293,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   ASSERT_GE(aligned_allocs_intercepted_by_size[61], 1u);
 #endif  // !OS_WIN
 
-#if !defined(OS_WIN) && !defined(OS_MACOSX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void* memalign_ptr = memalign(128, 53);
   ASSERT_NE(nullptr, memalign_ptr);
   ASSERT_EQ(0u, reinterpret_cast<uintptr_t>(memalign_ptr) % 128);
@@ -306,7 +306,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   ASSERT_GE(aligned_allocs_intercepted_by_alignment[kPageSize], 1u);
   // pvalloc rounds the size up to the next page.
   ASSERT_GE(aligned_allocs_intercepted_by_size[kPageSize], 1u);
-#endif  // !OS_WIN && !OS_MACOSX
+#endif  // !OS_WIN && !OS_MACOSX && !OS_BSD
 
   char* realloc_ptr = static_cast<char*>(malloc(10));
   strcpy(realloc_ptr, "foobar");
@@ -322,13 +322,13 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   free(zero_alloc_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(zero_alloc_ptr)], 1u);
 
-#if !defined(OS_WIN) && !defined(OS_MACOSX)
+#if !defined(OS_WIN) && !defined(OS_MACOSX) && !defined(OS_BSD)
   free(memalign_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(memalign_ptr)], 1u);
 
   free(pvalloc_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(pvalloc_ptr)], 1u);
-#endif  // !OS_WIN && !OS_MACOSX
+#endif  // !OS_WIN && !OS_MACOSX && !OS_BSD
 
 #if !defined(OS_WIN)
   free(posix_memalign_ptr);
