--- content/common/file_path_watcher/file_path_watcher_stub.cc.orig	2011-04-26 11:01:09.000000000 +0300
+++ content/common/file_path_watcher/file_path_watcher_stub.cc	2011-05-04 01:10:53.819147264 +0300
@@ -5,15 +5,23 @@
 // This file exists for Unix systems which don't have the inotify headers, and
 // thus cannot build file_watcher_inotify.cc
 
-#include "chrome/common/file_path_watcher/file_path_watcher.h"
+#include "content/common/file_path_watcher/file_path_watcher.h"
 
 class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
  public:
+
   virtual bool Watch(const FilePath& path,
-                     FileWatcher::Delegate* delegate,
-                     base::MessageLoopProxy*) OVERRIDE {
+                     FilePathWatcher::Delegate* delegate) OVERRIDE {
     return false;
   }
+
+  virtual void Cancel() OVERRIDE {
+    set_cancelled();
+  }
+
+ protected:
+
+  virtual void CancelOnMessageLoopThread() OVERRIDE { }
 };
 
 FilePathWatcher::FilePathWatcher() {
