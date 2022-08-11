--- meilisearch-http/build.rs.orig	2022-05-17 10:09:16 UTC
+++ meilisearch-http/build.rs
@@ -18,7 +18,7 @@ mod mini_dashboard {
 
     use anyhow::Context;
     use cargo_toml::Manifest;
-    use reqwest::blocking::get;
+    use std::fs;
     use sha1::{Digest, Sha1};
     use static_files::resource_dir;
 
@@ -51,12 +51,10 @@ mod mini_dashboard {
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
