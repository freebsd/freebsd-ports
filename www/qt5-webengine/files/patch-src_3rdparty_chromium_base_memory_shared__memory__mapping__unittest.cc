--- src/3rdparty/chromium/base/memory/shared_memory_mapping_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/memory/shared_memory_mapping_unittest.cc
@@ -12,6 +12,7 @@
 #include "base/containers/span.h"
 #include "base/memory/read_only_shared_memory_region.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#include "base/sys_byteorder.h"
 
 namespace base {
 
@@ -69,8 +70,8 @@ TEST_F(SharedMemoryMappingTest, SpanWithAutoDeducedEle
 
   for (size_t i = 0; i < write_span.size(); ++i)
     write_span[i] = i + 1;
-  EXPECT_EQ(0x04030201u, read_span[0]);
-  EXPECT_EQ(0x08070605u, read_span[1]);
+  EXPECT_EQ(HostToNet32(0x01020304u), read_span[0]);
+  EXPECT_EQ(HostToNet32(0x05060708u), read_span[1]);
 }
 
 TEST_F(SharedMemoryMappingTest, SpanWithExplicitElementCount) {
@@ -95,13 +96,13 @@ TEST_F(SharedMemoryMappingTest, SpanWithExplicitElemen
 
   for (size_t i = 0; i < write_span.size(); ++i)
     write_span[i] = i + 1;
-  EXPECT_EQ(0x04030201u, read_span[0]);
-  EXPECT_EQ(0x08070605u, read_span[1]);
-  EXPECT_EQ(0x04030201u, read_span_2[0]);
+  EXPECT_EQ(HostToNet32(0x01020304u), read_span[0]);
+  EXPECT_EQ(HostToNet32(0x05060708u), read_span[1]);
+  EXPECT_EQ(HostToNet32(0x01020304u), read_span_2[0]);
 
   std::fill(write_span_2.begin(), write_span_2.end(), 0);
   EXPECT_EQ(0u, read_span[0]);
-  EXPECT_EQ(0x08070605u, read_span[1]);
+  EXPECT_EQ(HostToNet32(0x05060708u), read_span[1]);
   EXPECT_EQ(0u, read_span_2[0]);
 }
 
