--- src/3rdparty/chromium/components/safe_browsing/db/util_unittest.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/safe_browsing/db/util_unittest.cc
@@ -12,6 +12,12 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "url/gurl.h"
 
+#if defined(OS_WIN)
+#include <winsock2.h>
+#elif defined(OS_POSIX)
+#include <arpa/inet.h>
+#endif
+
 namespace safe_browsing {
 
 TEST(SafeBrowsingDbUtilTest, UrlToFullHashes) {
@@ -83,7 +89,7 @@ TEST(SafeBrowsingDbUtilTest, StringToSBFullHashAndSBFu
   // 31 chars plus the last \0 as full_hash.
   const std::string hash_in = "12345678902234567890323456789012";
   SBFullHash hash_out = StringToSBFullHash(hash_in);
-  EXPECT_EQ(0x34333231U, hash_out.prefix);
+  EXPECT_EQ(htonl(0x31323334U), hash_out.prefix);
   EXPECT_EQ(0, memcmp(hash_in.data(), hash_out.full_hash, sizeof(SBFullHash)));
 
   std::string hash_final = SBFullHashToString(hash_out);
