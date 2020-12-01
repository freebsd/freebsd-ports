--- base/allocator/allocator_shim_unittest.cc.orig	2020-11-13 06:36:34 UTC
+++ base/allocator/allocator_shim_unittest.cc
@@ -367,7 +367,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
 
 #endif  // !OS_WIN
 
-#if !defined(OS_WIN) && !defined(OS_APPLE)
+#if !defined(OS_WIN) && !defined(OS_APPLE) && !defined(OS_BSD)
   void* memalign_ptr = memalign(128, 53);
   ASSERT_NE(nullptr, memalign_ptr);
   ASSERT_EQ(0u, reinterpret_cast<uintptr_t>(memalign_ptr) % 128);
@@ -383,7 +383,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   ASSERT_GE(aligned_allocs_intercepted_by_size[kPageSize], 1u);
 #endif  // !defined(OS_ANDROID)
 
-#endif  // !OS_WIN && !OS_APPLE
+#endif  // !OS_WIN && !OS_APPLE && !OS_BSD
 
 // See allocator_shim_override_glibc_weak_symbols.h for why we intercept
 // internal libc symbols.
@@ -410,7 +410,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   free(zero_alloc_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(zero_alloc_ptr)], 1u);
 
-#if !defined(OS_WIN) && !defined(OS_APPLE)
+#if !defined(OS_WIN) && !defined(OS_APPLE) && !defined(OS_BSD)
   free(memalign_ptr);
   ASSERT_GE(frees_intercepted_by_addr[Hash(memalign_ptr)], 1u);
 
@@ -419,7 +419,7 @@ TEST_F(AllocatorShimTest, InterceptLibcSymbols) {
   ASSERT_GE(frees_intercepted_by_addr[Hash(pvalloc_ptr)], 1u);
 #endif  // !defined(OS_ANDROID)
 
-#endif  // !OS_WIN && !OS_APPLE
+#endif  // !OS_WIN && !OS_APPLE && !OS_BSD
 
 #if !defined(OS_WIN)
   free(posix_memalign_ptr);
@@ -595,7 +595,7 @@ static size_t GetAllocatedSize(void* ptr) {
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_size(ptr);
 }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 static size_t GetAllocatedSize(void* ptr) {
   return malloc_usable_size(ptr);
 }
