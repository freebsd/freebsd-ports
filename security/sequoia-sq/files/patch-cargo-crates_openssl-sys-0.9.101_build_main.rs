--- cargo-crates/openssl-sys-0.9.101/build/main.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-sys-0.9.101/build/main.rs
@@ -82,9 +82,11 @@ fn main() {
     // rerun-if-changed causes openssl-sys to rebuild if the openssl include
     // dir has changed since the last build. However, this causes a rebuild
     // every time when vendoring so we disable it.
-    #[cfg(not(feature = "vendored"))]
-    if let Some(printable_include) = include_dir.join("openssl").to_str() {
-        println!("cargo:rerun-if-changed={}", printable_include);
+    let potential_path = include_dir.join("openssl");
+    if potential_path.exists() && !cfg!(feature = "vendored") {
+        if let Some(printable_include) = potential_path.to_str() {
+            println!("cargo:rerun-if-changed={}", printable_include);
+        }
     }
 
     if !lib_dirs.iter().all(|p| p.exists()) {
@@ -300,6 +302,7 @@ See rust-openssl documentation for more information:
             (3, 8, 0) => ('3', '8', '0'),
             (3, 8, 1) => ('3', '8', '1'),
             (3, 8, _) => ('3', '8', 'x'),
+            (3, 9, 0) => ('3', '9', '0'),
             _ => version_error(),
         };
 
@@ -342,7 +345,7 @@ This crate is only compatible with OpenSSL (version 1.
         "
 
 This crate is only compatible with OpenSSL (version 1.0.1 through 1.1.1, or 3), or LibreSSL 2.5
-through 3.8.1, but a different version of OpenSSL was found. The build is now aborting
+through 3.9.0, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
