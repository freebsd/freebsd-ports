--- base/process/memory_unittest.cc.orig	2016-05-11 19:02:11 UTC
+++ base/process/memory_unittest.cc
@@ -140,11 +140,11 @@ TEST(ProcessMemoryTest, MacTerminateOnHe
 #endif  // defined(OS_MACOSX)
 
 // Android doesn't implement set_new_handler, so we can't use the
-// OutOfMemoryTest cases. OpenBSD does not support these tests either.
+// OutOfMemoryTest cases. OpenBSD and FreeBSD do not support these tests either.
 // Don't test these on ASan/TSan/MSan configurations: only test the real
 // allocator.
 // Windows only supports these tests with the allocator shim in place.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) &&   \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) &&   \
     !(defined(OS_WIN) && !defined(ALLOCATOR_SHIM)) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
@@ -474,5 +474,5 @@ TEST_F(OutOfMemoryHandledTest, Unchecked
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !(defined(OS_WIN) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) && !(defined(OS_WIN) &&
         // !defined(ALLOCATOR_SHIM)) && !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
