--- src/interactive/app/handlers.rs.orig	2021-06-29 23:43:34 UTC
+++ src/interactive/app/handlers.rs
@@ -229,6 +229,7 @@ impl AppState {
                     self.message = None;
                     res
                 }
+                #[cfg(feature = "trash-move")]
                 Some(MarkMode::Trash) => {
                     self.message = Some("Trashing entries...".to_string());
                     let mut entries_trashed = 0;
@@ -272,6 +273,7 @@ impl AppState {
         Ok(entries_deleted)
     }
 
+    #[cfg(feature = "trash-move")]
     pub fn trash_entry(
         &mut self,
         index: TreeIndex,
