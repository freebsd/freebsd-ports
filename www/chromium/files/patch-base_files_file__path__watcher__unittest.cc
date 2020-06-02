--- base/files/file_path_watcher_unittest.cc.orig	2020-05-13 18:40:16 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -430,7 +430,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
@@ -803,7 +803,7 @@ enum Permission {
   Execute
 };
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -832,9 +832,9 @@ bool ChangeFilePermissions(const FilePath& path, Permi
   }
   return chmod(path.value().c_str(), stat_buf.st_mode) == 0;
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) || defined(OS_BSD)
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
@@ -869,7 +869,7 @@ TEST_F(FilePathWatcherTest, DirAttributesChanged) {
   ASSERT_TRUE(ChangeFilePermissions(test_dir1, Execute, true));
 }
 
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_BSD
 }  // namespace
 
 }  // namespace base
