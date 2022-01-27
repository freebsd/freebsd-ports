--- meilisearch-http/build.rs.orig	2022-01-27 19:17:02 UTC
+++ meilisearch-http/build.rs
@@ -19,7 +19,7 @@ mod mini_dashboard {
     use actix_web_static_files::resource_dir;
     use anyhow::Context;
     use cargo_toml::Manifest;
-    use reqwest::blocking::get;
+    use std::fs;
     use sha1::{Digest, Sha1};
 
     pub fn setup_mini_dashboard() -> anyhow::Result<()> {
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
