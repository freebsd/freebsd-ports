--- base/allocator/partition_allocator/partition_page.h.orig	2022-02-07 13:39:41 UTC
+++ base/allocator/partition_allocator/partition_page.h
@@ -141,7 +141,8 @@ struct __attribute__((packed)) SlotSpanMetadata {
   // in PartitionPage, which has other fields as well, and must fit in 32 bytes.
 
   // CHECK()ed in AllocNewSlotSpan().
-#if defined(PA_HAS_64_BITS_POINTERS) && defined(OS_APPLE)
+#if (defined(PA_HAS_64_BITS_POINTERS) && defined(OS_APPLE)) || \
+    (defined(OS_FREEBSD) && defined(__i386__))
   // System page size is not a constant on Apple OSes, but is either 4 or 16kiB
   // (1 << 12 or 1 << 14), as checked in PartitionRoot::Init(). And
   // PartitionPageSize() is 4 times the OS page size.
