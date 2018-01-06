--- src/3rdparty/chromium/base/process/memory_unittest.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/memory_unittest.cc
@@ -82,10 +82,10 @@ TEST(MemoryTest, AllocatorShimWorking) {
   ASSERT_TRUE(base::allocator::IsAllocatorInitialized());
 }
 
-// OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
+// BSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_OPENBSD) && \
+#if !defined(OS_BSD) && \
     BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
@@ -439,5 +439,5 @@ TEST_F(OutOfMemoryHandledTest, Unchecked
   EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
   EXPECT_TRUE(value_ == NULL);
 }
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
