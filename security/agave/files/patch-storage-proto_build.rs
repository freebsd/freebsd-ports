--- storage-proto/build.rs.orig	2026-07-21 04:26:20 UTC
+++ storage-proto/build.rs
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
     let proto_base_path = std::path::PathBuf::from("proto");
     let proto_files = [
         "confirmed_block.proto",
