--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -1305,7 +1305,7 @@ TEST_F(PartitionAllocTest, LostFreePagesBug) {
 #if !defined(OS_WIN) &&            \
     (!defined(ARCH_CPU_64_BITS) || \
      (defined(OS_POSIX) &&         \
-      !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID))))
+      !(defined(OS_FUCHSIA) || defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_BSD))))
 
 // The following four tests wrap a called function in an expect death statement
 // to perform their test, because they are non-hermetic. Specifically they are
