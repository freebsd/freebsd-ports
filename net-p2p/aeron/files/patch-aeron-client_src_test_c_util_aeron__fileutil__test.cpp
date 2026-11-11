--- aeron-client/src/test/c/util/aeron_fileutil_test.cpp.orig	2024-12-10 01:20:47 UTC
+++ aeron-client/src/test/c/util/aeron_fileutil_test.cpp
@@ -369,6 +369,9 @@ TEST_F(FileUtilTest, shouldMsyncMappedFile)

 TEST_F(FileUtilTest, shouldErrorIfMSyncingNonMappedData)
 {
+#if defined(__FreeBSD__)
+    GTEST_SKIP() << "FreeBSD msync(2) succeeds for mapped pages regardless of file-backing";
+#endif
     char data[10];
     ASSERT_EQ(-1, aeron_msync(&data, 1));
     ASSERT_NE(0, aeron_errcode());
