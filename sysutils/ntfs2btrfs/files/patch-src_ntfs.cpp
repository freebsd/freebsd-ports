--- src/ntfs.cpp.orig	2023-05-01 20:59:36 UTC
+++ src/ntfs.cpp
@@ -465,7 +465,7 @@ string_view ntfs::find_sd(uint32_t id, ntfs_file& secu
 }
 
 static void walk_btree(const index_root& ir, const list<mapping>& mappings, const index_node_header& inh, ntfs& dev,
-                       const invocable<const index_entry&, string_view> auto& func, unsigned int level) {
+                       const function<void(const index_entry&, string_view)>& func, unsigned int level) {
     auto ent = reinterpret_cast<const index_entry*>((uint8_t*)&inh + inh.first_entry);
 
     do {
