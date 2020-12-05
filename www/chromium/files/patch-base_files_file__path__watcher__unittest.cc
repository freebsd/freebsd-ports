--- base/files/file_path_watcher_unittest.cc.orig	2020-11-13 06:36:34 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -425,12 +425,12 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
   ASSERT_TRUE(WaitForEvents());
-#endif  // !OS_APPLE
+#endif  // !OS_APPLE && !OS_BSD
 
   ASSERT_TRUE(base::DeleteFile(file1));
   VLOG(1) << "Waiting for file1 deletion";
@@ -632,7 +632,7 @@ TEST_F(FilePathWatcherTest, FileAttributesChanged) {
   ASSERT_TRUE(WaitForEvents());
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Verify that creating a symlink is caught.
 TEST_F(FilePathWatcherTest, CreateLink) {
@@ -790,7 +790,7 @@ TEST_F(FilePathWatcherTest, LinkedDirectoryPart3) {
   ASSERT_TRUE(WaitForEvents());
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 enum Permission {
   Read,
@@ -798,7 +798,7 @@ enum Permission {
   Execute
 };
 
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -827,9 +827,9 @@ bool ChangeFilePermissions(const FilePath& path, Permi
   }
   return chmod(path.value().c_str(), stat_buf.st_mode) == 0;
 }
-#endif  // defined(OS_APPLE)
+#endif  // defined(OS_APPLE) || defined(OS_BSD)
 
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
@@ -864,7 +864,7 @@ TEST_F(FilePathWatcherTest, DirAttributesChanged) {
   ASSERT_TRUE(ChangeFilePermissions(test_dir1, Execute, true));
 }
 
-#endif  // OS_APPLE
+#endif  // OS_APPLE || OS_BSD
 }  // namespace
 
 }  // namespace base
