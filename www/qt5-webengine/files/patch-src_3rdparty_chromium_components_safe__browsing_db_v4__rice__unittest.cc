--- src/3rdparty/chromium/components/safe_browsing/db/v4_rice_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/safe_browsing/db/v4_rice_unittest.cc
@@ -6,6 +6,12 @@
 #include "base/logging.h"
 #include "testing/platform_test.h"
 
+#if defined(OS_WIN)
+#include <winsock2.h>
+#elif defined(OS_POSIX)
+#include <arpa/inet.h>
+#endif
+
 using ::google::protobuf::RepeatedField;
 using ::google::protobuf::int32;
 
@@ -247,7 +253,7 @@ TEST_F(V4RiceTest, TestDecoderPrefixesWithOneValue) {
   EXPECT_EQ(DECODE_SUCCESS,
             V4RiceDecoder::DecodePrefixes(0x69F67F51u, 2, 0, "", &out));
   EXPECT_EQ(1u, out.size());
-  EXPECT_EQ(0x69F67F51u, out[0]);
+  EXPECT_EQ(htonl(0x517FF669u), out[0]);
 }
 
 TEST_F(V4RiceTest, TestDecoderPrefixesWithMultipleValues) {
@@ -256,7 +262,7 @@ TEST_F(V4RiceTest, TestDecoderPrefixesWithMultipleValu
             V4RiceDecoder::DecodePrefixes(
                 5, 28, 3, "\xbf\xa8\x3f\xfb\xf\xf\x5e\x27\xe6\xc3\x1d\xc6\x38",
                 &out));
-  std::vector<uint32_t> expected = {5, 0xad934c0cu, 0x6ff67f56u, 0x81316fceu};
+  std::vector<uint32_t> expected = {htonl(0x05000000), htonl(0x0c4c93adu), htonl(0x567ff66fu), htonl(0xce6f3181u)};
   EXPECT_EQ(expected.size(), out.size());
   for (unsigned i = 0; i < expected.size(); i++) {
     EXPECT_EQ(expected[i], out[i]);
