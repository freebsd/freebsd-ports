--- base/files/file_path_watcher_unittest.cc.orig	2018-08-08 21:10:31.000000000 +0200
+++ base/files/file_path_watcher_unittest.cc	2018-08-29 20:20:06.152675000 +0200
@@ -435,7 +435,7 @@
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
