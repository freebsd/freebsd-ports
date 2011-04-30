--- content/common/file_path_watcher/file_path_watcher_stub.cc.orig	2011-04-15 11:01:10.000000000 +0300
+++ content/common/file_path_watcher/file_path_watcher_stub.cc	2011-04-19 22:34:32.353038862 +0300
@@ -5,15 +5,21 @@
 // This file exists for Unix systems which don't have the inotify headers, and
 // thus cannot build file_watcher_inotify.cc
 
-#include "chrome/common/file_path_watcher/file_path_watcher.h"
+#include "content/common/file_path_watcher/file_path_watcher.h"
 
 class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
  public:
+
+  virtual void Cancel() {}
+
   virtual bool Watch(const FilePath& path,
-                     FileWatcher::Delegate* delegate,
-                     base::MessageLoopProxy*) OVERRIDE {
+                     FilePathWatcher::Delegate* delegate) OVERRIDE {
     return false;
   }
+
+ protected:
+
+  virtual void CancelOnMessageLoopThread() {}
 };
 
 FilePathWatcher::FilePathWatcher() {
