--- meilisearch/build.rs.orig	2023-05-30 18:20:28 UTC
+++ meilisearch/build.rs
@@ -1,17 +1,6 @@
-use vergen::{vergen, Config, SemverKind};
-
 fn main() {
-    // Note: any code that needs VERGEN_ environment variables should take care to define them manually in the Dockerfile and pass them
-    // in the corresponding GitHub workflow (publish_docker.yml).
-    // This is due to the Dockerfile building the binary outside of the git directory.
-    let mut config = Config::default();
-    // allow using non-annotated tags
-    *config.git_mut().semver_kind_mut() = SemverKind::Lightweight;
+    println!("cargo:rustc-env=VERGEN_GIT_SEMVER_LIGHTWEIGHT=%%GH_TAGNAME%%");

-    if let Err(e) = vergen(config) {
-        println!("cargo:warning=vergen: {}", e);
-    }
-
     #[cfg(feature = "mini-dashboard")]
     mini_dashboard::setup_mini_dashboard().expect("Could not load the mini-dashboard assets");
 }
@@ -25,9 +14,9 @@ mod mini_dashboard {
 
     use anyhow::Context;
     use cargo_toml::Manifest;
-    use reqwest::blocking::get;
     use sha1::{Digest, Sha1};
     use static_files::resource_dir;
+    use std::fs;
 
     pub fn setup_mini_dashboard() -> anyhow::Result<()> {
         let cargo_manifest_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());
@@ -59,11 +61,10 @@ mod mini_dashboard {
         }
 
         let url = meta["assets-url"].as_str().unwrap();
+        let dashboard_assets_bytes = fs::read("%%MINIDASHBOARDFILE%%")?;
 
-        let dashboard_assets_bytes = get(url)?.bytes()?;
-
         let mut hasher = Sha1::new();
-        hasher.update(&dashboard_assets_bytes);
+        hasher.update(dashboard_assets_bytes.as_slice());
         let sha1 = hex::encode(hasher.finalize());
 
         assert_eq!(
