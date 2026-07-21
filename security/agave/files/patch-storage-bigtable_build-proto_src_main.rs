--- storage-bigtable/build-proto/src/main.rs.orig	2026-07-21 04:26:20 UTC
+++ storage-bigtable/build-proto/src/main.rs
@@ -1,13 +1,4 @@ fn main() -> Result<(), std::io::Error> {
 fn main() -> Result<(), std::io::Error> {
-    const PROTOC_ENVAR: &str = "PROTOC";
-    // Safety: env is checked and updated before any threads might exist
-    if std::env::var(PROTOC_ENVAR).is_err() {
-        #[cfg(not(windows))]
-        unsafe {
-            std::env::set_var(PROTOC_ENVAR, protobuf_src::protoc())
-        }
-    }
-
     let manifest_dir = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"));
 
     let out_dir = manifest_dir.join("../proto");
