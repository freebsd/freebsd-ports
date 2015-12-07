--- base/process/memory_unittest.cc.orig	2015-10-14 03:01:18.000000000 -0400
+++ base/process/memory_unittest.cc	2015-10-23 11:11:40.281381000 -0400
@@ -137,11 +137,11 @@
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
 
@@ -483,5 +483,5 @@
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !(defined(OS_WIN) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) && !defined(OS_WIN)
         // !defined(ALLOCATOR_SHIM)) && !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
