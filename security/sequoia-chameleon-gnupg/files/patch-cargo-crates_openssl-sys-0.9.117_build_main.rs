--- cargo-crates/openssl-sys-0.9.117/build/main.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-sys-0.9.117/build/main.rs
@@ -163,6 +163,7 @@ fn main() {
     println!("cargo:rustc-check-cfg=cfg(libressl410)");
     println!("cargo:rustc-check-cfg=cfg(libressl420)");
     println!("cargo:rustc-check-cfg=cfg(libressl430)");
+    println!("cargo:rustc-check-cfg=cfg(libressl440)");
 
     println!("cargo:rustc-check-cfg=cfg(ossl101)");
     println!("cargo:rustc-check-cfg=cfg(ossl102)");
@@ -430,6 +431,7 @@ See rust-openssl documentation for more information:
             (4, 1, _) => ('4', '1', 'x'),
             (4, 2, _) => ('4', '2', 'x'),
             (4, 3, _) => ('4', '3', 'x'),
+            (4, 4, _) => ('4', '4', 'x'),
             _ => version_error(),
         };
 
@@ -468,7 +470,7 @@ This crate is only compatible with OpenSSL (version 1.
         "
 
 This crate is only compatible with OpenSSL (version 1.1.0, 1.1.1, 3.x, or 4.x), or LibreSSL 3.5.0
-through 4.3.x, but a different version of OpenSSL was found. The build is now aborting
+through 4.4.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
