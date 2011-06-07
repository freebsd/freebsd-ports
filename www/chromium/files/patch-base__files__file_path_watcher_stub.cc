--- base/files/file_path_watcher_stub.cc.orig	2011-05-06 12:03:16.000000000 +0300
+++ base/files/file_path_watcher_stub.cc	2011-06-04 15:41:10.461378331 +0300
@@ -15,10 +15,16 @@
 class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
  public:
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
+  virtual void CancelOnMessageLoopThread() OVERRIDE { }
 };
 
 }  // namespace
