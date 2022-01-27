--- ../lmdb-rs-d0b50d02938ee84e4e4372697ea991fe2a4cae3b/lmdb-sys/build.rs.orig
+++ ../lmdb-rs-d0b50d02938ee84e4e4372697ea991fe2a4cae3b/lmdb-sys/build.rs
@@ -59,7 +59,7 @@
         warn!("Building with `-fsanitize=fuzzer`.");
     }
 
-    if !pkg_config::find_library("liblmdb").is_ok() {
+    if !pkg_config::find_library("lmdb").is_ok() {
         let mut builder = cc::Build::new();
 
         builder
