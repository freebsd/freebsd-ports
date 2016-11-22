--- base/process/memory_unittest.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/process/memory_unittest.cc	2016-10-13 04:32:50.457987000 +0300
@@ -82,10 +82,10 @@
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
 
@@ -439,5 +439,5 @@
   EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
   EXPECT_TRUE(value_ == NULL);
 }
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
