--- base/memory/shared_memory_region_unittest.cc.orig	2020-03-23 16:31:23 UTC
+++ base/memory/shared_memory_region_unittest.cc
@@ -188,10 +188,13 @@ TYPED_TEST(SharedMemoryRegionTest, MapAtNotAlignedOffs
   std::tie(region, rw_mapping) = CreateMappedRegion<TypeParam>(kDataSize);
   ASSERT_TRUE(region.IsValid());
   ASSERT_TRUE(rw_mapping.IsValid());
+#if !defined(OS_BSD)
+  // On FreeBSD, mmap() does not require an aligned offset
   off_t offset = kDataSize / 2;
   typename TypeParam::MappingType mapping =
       region.MapAt(offset, kDataSize - offset);
   EXPECT_FALSE(mapping.IsValid());
+#endif
 }
 
 TYPED_TEST(SharedMemoryRegionTest, MapZeroBytesFails) {
