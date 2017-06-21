--- base/process/memory_unittest.cc.orig	2017-06-05 19:03:00 UTC
+++ base/process/memory_unittest.cc
@@ -101,10 +101,10 @@ TEST(MemoryTest, AllocatorShimWorking) {
 #endif
 }
 
-// OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
+// BSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_OPENBSD) && \
+#if !defined(OS_BSD) && \
     BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
@@ -508,5 +508,5 @@ TEST_F(OutOfMemoryHandledTest, UncheckedCalloc) {
   EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
   EXPECT_TRUE(value_ == NULL);
 }
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
