--- meilisearch/build.rs.orig	2023-02-23 13:52:56 UTC
+++ meilisearch/build.rs
@@ -4,6 +4,8 @@ fn main() {
     if let Err(e) = vergen(Config::default()) {
         println!("cargo:warning=vergen: {}", e);
     }
+    println!("cargo:rustc-env=VERGEN_GIT_SHA=%%COMMIT_SHA%%");
+    println!("cargo:rustc-env=VERGEN_GIT_COMMIT_TIMESTAMP=%%COMMIT_TS%%");

     #[cfg(feature = "mini-dashboard")]
     mini_dashboard::setup_mini_dashboard().expect("Could not load the mini-dashboard assets");
@@ -18,9 +20,9 @@ mod mini_dashboard {
 
     use anyhow::Context;
     use cargo_toml::Manifest;
-    use reqwest::blocking::get;
     use sha1::{Digest, Sha1};
     use static_files::resource_dir;
+    use std::fs;
 
     pub fn setup_mini_dashboard() -> anyhow::Result<()> {
         let cargo_manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());
@@ -51,12 +53,10 @@ mod mini_dashboard {
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
