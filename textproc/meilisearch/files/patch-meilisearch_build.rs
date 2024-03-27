--- meilisearch/build.rs.orig	2024-03-21 11:21:56 UTC
+++ meilisearch/build.rs
@@ -12,9 +12,9 @@ mod mini_dashboard {
 
     use anyhow::Context;
     use cargo_toml::Manifest;
-    use reqwest::blocking::get;
     use sha1::{Digest, Sha1};
     use static_files::resource_dir;
+    use std::fs;
 
     pub fn setup_mini_dashboard() -> anyhow::Result<()> {
         let cargo_manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());
@@ -45,12 +45,10 @@ mod mini_dashboard {
             }
         }
 
-        let url = meta["assets-url"].as_str().unwrap();
+        let dashboard_assets_bytes = fs::read("%%MINIDASHBOARDFILE%%")?;
 
-        let dashboard_assets_bytes = get(url)?.bytes()?;
-
         let mut hasher = Sha1::new();
-        hasher.update(&dashboard_assets_bytes);
+        hasher.update(dashboard_assets_bytes.as_slice());
         let sha1 = hex::encode(hasher.finalize());
 
         assert_eq!(
