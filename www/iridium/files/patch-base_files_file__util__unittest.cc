--- base/files/file_util_unittest.cc.orig	2020-03-23 13:34:59 UTC
+++ base/files/file_util_unittest.cc
@@ -3434,7 +3434,7 @@ TEST_F(FileUtilTest, ReadFileToStringWithNamedPipe) {
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 TEST_F(FileUtilTest, ReadFileToStringWithProcFileSystem) {
   FilePath file_path("/proc/cpuinfo");
   std::string data = "temp";
@@ -3452,7 +3452,7 @@ TEST_F(FileUtilTest, ReadFileToStringWithProcFileSyste
 
   EXPECT_FALSE(ReadFileToStringWithMaxSize(file_path, nullptr, 4));
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 TEST_F(FileUtilTest, ReadFileToStringWithLargeFile) {
   std::string data(kLargeFileSize, 'c');
