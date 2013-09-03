--- base/process_util_unittest.cc.orig	2013-08-31 13:38:46.000000000 +0300
+++ base/process_util_unittest.cc	2013-08-31 13:40:13.000000000 +0300
@@ -1086,7 +1086,7 @@
 // functions so that they don't crash if the program is out of memory, so the
 // OOM tests aren't supposed to work.
 // TODO(vandebo) make this work on Windows too.
-#if !defined(OS_ANDROID) && !defined(OS_OPENBSD) && \
+#if !defined(OS_ANDROID) && !defined(OS_BSD) && \
     !defined(OS_WIN) && \
     !defined(ADDRESS_SANITIZER) && !defined(THREAD_SANITIZER)
 
@@ -1303,5 +1303,5 @@
 #endif  // !ARCH_CPU_64_BITS
 #endif  // OS_MACOSX
 
-#endif  // !defined(OS_ANDROID) && !defined(OS_OPENBSD) &&
+#endif  // !defined(OS_ANDROID) && !defined(OS_BSD) &&
         // !defined(OS_WIN) && !defined(ADDRESS_SANITIZER)
