diff --git src/engine/api/geary-aggregated-folder-properties.vala src/engine/api/geary-aggregated-folder-properties.vala
index ea165e2..986b9e6 100644
--- src/engine/api/geary-aggregated-folder-properties.vala.orig
+++ src/engine/api/geary-aggregated-folder-properties.vala
@@ -23,7 +23,7 @@ private class Geary.AggregatedFolderProperties : Geary.FolderProperties {
      */
     public AggregatedFolderProperties(bool is_local_only, bool is_virtual) {
         // Set defaults.
-        base(0, 0, Trillian.UNKNOWN, Trillian.UNKNOWN, Trillian.UNKNOWN, is_local_only, is_virtual);
+        base(0, 0, Trillian.UNKNOWN, Trillian.UNKNOWN, Trillian.UNKNOWN, is_local_only, is_virtual, false);
     }
     
     /**
