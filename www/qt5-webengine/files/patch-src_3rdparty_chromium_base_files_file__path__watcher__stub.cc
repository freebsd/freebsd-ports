--- src/3rdparty/chromium/base/files/file_path_watcher_stub.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/files/file_path_watcher_stub.cc
@@ -5,10 +5,14 @@
 // This file exists for Unix systems which don't have the inotify headers, and
 // thus cannot build file_watcher_inotify.cc
 
+#include <memory>
+
 #include "base/files/file_path_watcher.h"
+#include "base/files/file_path_watcher_kqueue.h"
 
 #include "base/macros.h"
 #include "base/memory/ptr_util.h"
+#include "build/build_config.h"
 
 namespace base {
 
@@ -22,12 +26,26 @@ class FilePathWatcherImpl : public FilePathWatcher::Pl
   bool Watch(const FilePath& path,
              bool recursive,
              const FilePathWatcher::Callback& callback) override {
-    return false;
+    DCHECK(!impl_.get());
+    if (recursive) {
+      if (!FilePathWatcher::RecursiveWatchAvailable())
+        return false;
+    } else {
+     impl_ = std::make_unique<FilePathWatcherKQueue>();
+    }
+    DCHECK(impl_.get());
+    return impl_->Watch(path, recursive, callback);
   }
 
-  void Cancel() override {}
+  void Cancel() override {
+    if (impl_.get())
+      impl_->Cancel();
+    set_cancelled();
+  }
 
  private:
+  std::unique_ptr<PlatformDelegate> impl_;
+
   DISALLOW_COPY_AND_ASSIGN(FilePathWatcherImpl);
 };
 
