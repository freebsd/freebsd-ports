--- base/files/file_path_watcher_unittest.cc.orig	2019-10-21 19:06:18 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -435,7 +435,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
