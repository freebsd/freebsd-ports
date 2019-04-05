--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -734,7 +734,10 @@ class MediaFileSystemRegistry::MediaFileSystemContextI
 // Constructor in 'private' section because depends on private class definition.
 MediaFileSystemRegistry::MediaFileSystemRegistry()
     : file_system_context_(new MediaFileSystemContextImpl) {
-  StorageMonitor::GetInstance()->AddObserver(this);
+  // This conditional is needed for shutdown.  Destructors
+  // try to get the media file system registry.
+  if (StorageMonitor::GetInstance())
+    StorageMonitor::GetInstance()->AddObserver(this);
 }
 
 MediaFileSystemRegistry::~MediaFileSystemRegistry() {
