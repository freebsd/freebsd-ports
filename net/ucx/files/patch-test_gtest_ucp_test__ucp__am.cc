--- test/gtest/ucp/test_ucp_am.cc.orig	2026-09-09 16:06:37 UTC
+++ test/gtest/ucp/test_ucp_am.cc
@@ -129,7 +129,9 @@ ucs_status_t test_ucp_am::am_handler(test_ucp_am *me, 
     std::vector<char> cmp(length, (char)length);
     std::vector<char> databuf(length, 'r');
 
-    memcpy(&databuf[0], data, length);
+    if (length > 0) {
+        memcpy(&databuf[0], data, length);
+    }
 
     EXPECT_EQ(cmp, databuf);
 
