--- base/process/memory_unittest.cc.orig	2014-10-02 17:18:52 UTC
+++ base/process/memory_unittest.cc
@@ -160,9 +160,9 @@
 
 // Android doesn't implement set_new_handler, so we can't use the
 // OutOfMemoryTest cases.
-// OpenBSD does not support these tests either.
+// OpenBSD and FreeBSD do not support these tests either.
 // TODO(vandebo) make this work on Windows too.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) && \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) && \
     !defined(OS_WIN)
 
 #if defined(USE_TCMALLOC)
@@ -448,4 +448,4 @@
   EXPECT_TRUE(value_ == NULL);
 }
 #endif  // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) && !defined(OS_WIN)
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) && !defined(OS_WIN)
