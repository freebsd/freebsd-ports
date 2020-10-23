--- base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2020-09-08 19:13:57 UTC
+++ base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -313,9 +313,13 @@ void FreeFullPage(PartitionRoot<base::internal::Thread
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool CheckPageInCore(void* ptr, bool in_core) {
+#if defined(OS_BSD)
+  char ret = 0;
+#else
   unsigned char ret = 0;
+#endif
   EXPECT_EQ(0, mincore(ptr, kSystemPageSize, &ret));
   return in_core == (ret & 1);
 }
