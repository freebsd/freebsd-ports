--- base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2018-12-04 10:27:52.648233000 +0100
+++ base/allocator/partition_allocator/partition_alloc_unittest.cc	2018-12-04 10:31:38.008927000 +0100
@@ -1324,7 +1324,7 @@
 #if !defined(OS_WIN) &&            \
     (!defined(ARCH_CPU_64_BITS) || \
      (defined(OS_POSIX) &&         \
-      !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID))))
+      !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_BSD))))
 
 // The following four tests wrap a called function in an expect death statement
 // to perform their test, because they are non-hermetic. Specifically they are
