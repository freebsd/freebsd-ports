--- chrome/browser/media_galleries/media_file_system_registry.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/media_galleries/media_file_system_registry.cc
@@ -735,7 +735,10 @@ class MediaFileSystemRegistry::MediaFileSystemContextI
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
