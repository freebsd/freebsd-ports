--- content/browser/download/save_package.cc.orig	2023-12-23 12:33:28 UTC
+++ content/browser/download/save_package.cc
@@ -767,8 +767,13 @@ void SavePackage::Finish() {
   if (download_) {
     std::vector<download::DownloadSaveItemData::ItemInfo> files;
     for (auto& item : saved_success_items_) {
+#if defined(__clang__) && (__clang_major__ >= 16)
       files.emplace_back(item.second->full_path(), item.second->url(),
                          item.second->referrer().url);
+#else
+      files.emplace_back(download::DownloadSaveItemData::ItemInfo{item.second->full_path(), item.second->url(),
+                         item.second->referrer().url});
+#endif
     }
     download::DownloadSaveItemData::AttachItemData(download_, std::move(files));
   }
