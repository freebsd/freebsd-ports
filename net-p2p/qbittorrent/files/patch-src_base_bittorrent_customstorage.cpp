-- Fix build with libtorrent-rasterbar 2.1.
-- storage_params.path is now a string_view, renamed_files replaced
-- mapped_files, and file_storage::rename_file() is deprecated. Use the
-- public filenames view and renamed_files::rename_file() instead.

--- src/base/bittorrent/customstorage.cpp.orig	2024-01-07 17:14:52 UTC
+++ src/base/bittorrent/customstorage.cpp
@@ -65,11 +65,12 @@
 {
     lt::storage_holder storageHolder = m_nativeDiskIO->new_torrent(storageParams, torrent);

-    const Path savePath {storageParams.path};
+    const Path savePath {std::string(storageParams.path)};
     m_storageData[storageHolder] =
     {
         savePath,
-        storageParams.mapped_files ? *storageParams.mapped_files : storageParams.files,
+        storageParams.files,
+        storageParams.renamed_files,
         storageParams.priorities
     };

@@ -156,7 +157,10 @@
             , [=, this, handler = std::move(handler)](const std::string &name, lt::file_index_t index, const lt::storage_error &error)
     {
         if (!error)
-            m_storageData[storage].files.rename_file(index, name);
+        {
+            StorageData &storageData = m_storageData[storage];
+            storageData.renamedFiles.rename_file(storageData.files, index, name);
+        }
         handler(name, index, error);
     });
 }
@@ -212,7 +216,7 @@
 void CustomDiskIOThread::handleCompleteFiles(lt::storage_index_t storage, const Path &savePath)
 {
     const StorageData storageData = m_storageData[storage];
-    const lt::file_storage &fileStorage = storageData.files;
+    const lt::filenames fileStorage(storageData.files, storageData.renamedFiles);
     for (const lt::file_index_t fileIndex : fileStorage.file_range())
     {
         // ignore files that have priority 0
