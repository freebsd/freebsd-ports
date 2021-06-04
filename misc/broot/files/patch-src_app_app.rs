--- src/app/app.rs.orig	2021-06-04 13:01:08 UTC
+++ src/app/app.rs
@@ -510,8 +510,10 @@ impl App {
         self.update_preview(con);
 
         #[cfg(feature="client-server")]
-        if let Ok(mut root) = self.root.lock() { // when does this not work ?
-            *root = self.state().selected_path().to_path_buf();
+        if let Ok(mut root) = self.root.lock() {
+            if let Some(path) = self.state().selected_path() {
+                *root = path.to_path_buf();
+            }
         }
 
         Ok(())
