--- base/process/memory_unittest.cc.orig	2015-07-15 16:29:55.000000000 -0400
+++ base/process/memory_unittest.cc	2015-07-21 19:03:40.407090000 -0400
@@ -127,11 +127,11 @@
 #endif  // defined(OS_MACOSX)
 
 // Android doesn't implement set_new_handler, so we can't use the
-// OutOfMemoryTest cases. OpenBSD does not support these tests either.
+// OutOfMemoryTest cases. OpenBSD and FreeBSD do not support these tests either.
 // Don't test these on ASan/TSan/MSan configurations: only test the real
 // allocator.
 // TODO(vandebo) make this work on Windows too.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !defined(OS_WIN) && \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) && !defined(OS_WIN) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
 #if defined(USE_TCMALLOC)
@@ -415,5 +415,5 @@
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !defined(OS_WIN) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) && !defined(OS_WIN)
         // !defined(ADDRESS_SANITIZER)
