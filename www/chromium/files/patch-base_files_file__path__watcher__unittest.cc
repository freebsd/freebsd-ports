--- base/files/file_path_watcher_unittest.cc.orig	2022-02-28 16:54:41 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -450,7 +450,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
@@ -1038,7 +1038,7 @@ enum Permission {
   Execute
 };
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -1069,7 +1069,7 @@ bool ChangeFilePermissions(const FilePath& path, Permi
 }
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
