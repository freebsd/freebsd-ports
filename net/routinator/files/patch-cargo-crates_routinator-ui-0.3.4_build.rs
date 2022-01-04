--- cargo-crates/routinator-ui-0.3.4/build.rs.orig	2021-11-10 10:32:39 UTC
+++ cargo-crates/routinator-ui-0.3.4/build.rs
@@ -110,6 +110,8 @@ impl Assets {
 }
 
 fn _download_ui_release_build() -> Result<Vec<u8>, reqwest::Error> {
+    let fname = format!("{}/routinator-ui-build.tar.gz", "DISTDIR");
+    return Ok(std::fs::read(&fname).expect("could not read routinator ui file"));
     let version = env!("CARGO_PKG_VERSION");
     let mut headers = header::HeaderMap::new();
 
