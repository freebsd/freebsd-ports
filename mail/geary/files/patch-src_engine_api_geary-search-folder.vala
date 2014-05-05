diff --git src/engine/api/geary-search-folder.vala src/engine/api/geary-search-folder.vala
index 518b409..672853f 100644
--- src/engine/api/geary-search-folder.vala.orig
+++ src/engine/api/geary-search-folder.vala
@@ -14,7 +14,7 @@ public class Geary.SearchFolderRoot : Geary.FolderRoot {
 
 public class Geary.SearchFolderProperties : Geary.FolderProperties {
     public SearchFolderProperties(int total, int unread) {
-        base(total, unread, Trillian.FALSE, Trillian.FALSE, Trillian.TRUE, true, true);
+        base(total, unread, Trillian.FALSE, Trillian.FALSE, Trillian.TRUE, true, true, false);
     }
     
     public void set_total(int total) {
