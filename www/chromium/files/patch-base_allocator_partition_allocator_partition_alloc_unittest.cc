--- base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2018-08-23 19:18:25.616099000 +0200
+++ base/allocator/partition_allocator/partition_alloc_unittest.cc	2018-08-23 19:34:45.738651000 +0200
@@ -1297,7 +1297,7 @@
 // not provide a working setrlimit().
 #if !defined(ARCH_CPU_64_BITS) || \
     (defined(OS_POSIX) &&         \
-     !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID)))
+     !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_BSD)))
 
 // This is defined as a separate test class because RepeatedReturnNull
 // test exhausts the process memory, and breaks any test in the same
