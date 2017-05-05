--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc.orig	2017-04-19 09:33:16 UTC
+++ src/3rdparty/chromium/base/files/file_path_watcher_kqueue.cc
@@ -388,4 +388,10 @@ void FilePathWatcherKQueue::CancelOnMess
   }
 }
 
+// In the upstream version, this method is implemented in
+// file_path_watcher_mac.cc, which we obviously do not use.
+FilePathWatcher::FilePathWatcher() {
+  impl_ = new FilePathWatcherKQueue();
+}
+
 }  // namespace base
