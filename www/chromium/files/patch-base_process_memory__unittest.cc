--- base/process/memory_unittest.cc.orig	2017-09-05 21:05:11.000000000 +0200
+++ base/process/memory_unittest.cc	2017-09-06 16:53:33.919374000 +0200
@@ -104,7 +104,7 @@
 // OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
+#if !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
 namespace {
@@ -507,5 +507,5 @@
   EXPECT_FALSE(base::UncheckedCalloc(1, test_size_, &value_));
   EXPECT_TRUE(value_ == NULL);
 }
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(ENABLE_WIN_ALLOCATOR_SHIM_TESTS) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
