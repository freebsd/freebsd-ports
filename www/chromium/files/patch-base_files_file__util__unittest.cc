--- base/files/file_util_unittest.cc.orig	2021-12-31 00:57:18 UTC
+++ base/files/file_util_unittest.cc
@@ -1640,7 +1640,7 @@ TEST_F(FileUtilTest, DeleteDirRecursiveWithOpenFile) {
 #endif
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // This test will validate that files which would block when read result in a
 // failure on a call to ReadFileToStringNonBlocking. To accomplish this we will
 // use a named pipe because it appears as a file on disk and we can control how
@@ -1673,7 +1673,7 @@ TEST_F(FileUtilTest, TestNonBlockingFileReadLinux) {
   ASSERT_EQ(result.size(), 1u);
   EXPECT_EQ(result[0], 'a');
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 TEST_F(FileUtilTest, MoveFileNew) {
   // Create a file
@@ -3509,7 +3509,7 @@ TEST_F(FileUtilTest, ReadFileToStringWithNamedPipe) {
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_POSIX) && !defined(OS_APPLE)
+#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD)
 TEST_F(FileUtilTest, ReadFileToStringWithProcFileSystem) {
   FilePath file_path("/proc/cpuinfo");
   std::string data = "temp";
@@ -3527,7 +3527,7 @@ TEST_F(FileUtilTest, ReadFileToStringWithProcFileSyste
 
   EXPECT_FALSE(ReadFileToStringWithMaxSize(file_path, nullptr, 4));
 }
-#endif  // defined(OS_POSIX) && !defined(OS_APPLE)
+#endif  // defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD)
 
 TEST_F(FileUtilTest, ReadFileToStringWithLargeFile) {
   std::string data(kLargeFileSize, 'c');
