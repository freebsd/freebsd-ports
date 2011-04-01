--- chrome/browser/file_path_watcher/file_path_watcher_stub.cc.orig	2011-03-20 22:02:04.296736175 +0200
+++ chrome/browser/file_path_watcher/file_path_watcher_stub.cc	2011-03-20 22:02:04.454738659 +0200
@@ -9,7 +9,7 @@
 
 class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
  public:
-  virtual bool Watch(const FilePath& path, FileWatcher::Delegate* delegate) {
+  virtual bool Watch(const FilePath& path, FilePathWatcher::Delegate* delegate) {
     return false;
   }
 };
