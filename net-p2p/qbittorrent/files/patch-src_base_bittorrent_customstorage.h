-- Fix build with libtorrent-rasterbar 2.1.
-- In libtorrent 2.1, storage_params no longer has mapped_files; renamed
-- file overlays are kept in a separate renamed_files object. Store it so
-- we can reconstruct the filenames view later.
--- src/base/bittorrent/customstorage.h.orig	2024-01-07 17:14:52 UTC
+++ src/base/bittorrent/customstorage.h
@@ -97,6 +97,7 @@ private:
     struct StorageData
     {
         Path savePath;
         lt::file_storage files;
+        lt::renamed_files renamedFiles;
         lt::aux::vector<lt::download_priority_t, lt::file_index_t> filePriorities;
     };
     QHash<lt::storage_index_t, StorageData> m_storageData;
