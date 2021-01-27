--- base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2021-01-18 21:28:44 UTC
+++ base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -366,9 +366,13 @@ void FreeFullSlotSpan(PartitionRoot<base::internal::Th
   }
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool CheckPageInCore(void* ptr, bool in_core) {
+#if defined(OS_BSD)
+  char ret = 0;
+#else
   unsigned char ret = 0;
+#endif
   EXPECT_EQ(0, mincore(ptr, SystemPageSize(), &ret));
   return in_core == (ret & 1);
 }
@@ -377,7 +381,7 @@ bool CheckPageInCore(void* ptr, bool in_core) {
   EXPECT_TRUE(CheckPageInCore(ptr, in_core))
 #else
 #define CHECK_PAGE_IN_CORE(ptr, in_core) (void)(0)
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 class MockPartitionStatsDumper : public PartitionStatsDumper {
  public:
