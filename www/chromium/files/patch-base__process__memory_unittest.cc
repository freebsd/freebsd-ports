--- base/process/memory_unittest.cc.orig	2013-09-24 23:49:53.000000000 +0300
+++ base/process/memory_unittest.cc	2013-09-24 23:50:57.000000000 +0300
@@ -153,12 +153,12 @@
 
 // Android doesn't implement set_new_handler, so we can't use the
 // OutOfMemoryTest cases.
-// OpenBSD does not support these tests either.
+// OpenBSD and FreeBSD does not support these tests either.
 // AddressSanitizer and ThreadSanitizer define the malloc()/free()/etc.
 // functions so that they don't crash if the program is out of memory, so the
 // OOM tests aren't supposed to work.
 // TODO(vandebo) make this work on Windows too.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) && \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) && \
     !defined(OS_WIN) && \
     !defined(ADDRESS_SANITIZER) && !defined(THREAD_SANITIZER)
 
@@ -375,5 +375,5 @@
 #endif  // !ARCH_CPU_64_BITS
 #endif  // OS_MACOSX
 
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) &&
         // !defined(OS_WIN) && !defined(ADDRESS_SANITIZER)
