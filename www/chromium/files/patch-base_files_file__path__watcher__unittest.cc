--- base/files/file_path_watcher_unittest.cc.orig	2021-04-14 18:40:48 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -444,12 +444,12 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
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
@@ -822,7 +822,7 @@ TEST_F(FilePathWatcherTest, LinkedDirectoryPart3) {
   ASSERT_TRUE(WaitForEvents());
 }
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 enum Permission {
   Read,
@@ -830,7 +830,7 @@ enum Permission {
   Execute
 };
 
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -859,9 +859,9 @@ bool ChangeFilePermissions(const FilePath& path, Permi
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
@@ -897,7 +897,7 @@ TEST_F(FilePathWatcherTest, DirAttributesChanged) {
   ASSERT_TRUE(ChangeFilePermissions(test_dir1, Execute, true));
 }
 
-#endif  // OS_APPLE
+#endif  // OS_APPLE || OS_BSD
 
 #if defined(OS_MAC)
 
