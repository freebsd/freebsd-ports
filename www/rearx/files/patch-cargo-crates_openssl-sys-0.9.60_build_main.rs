--- cargo-crates/openssl-sys-0.9.60/build/main.rs.orig	2025-12-05 10:11:35.155113000 -0800
+++ cargo-crates/openssl-sys-0.9.60/build/main.rs	2025-12-05 10:11:41.989370000 -0800
@@ -237,7 +237,11 @@
         let openssl_version = openssl_version.unwrap();
         println!("cargo:version_number={:x}", openssl_version);
 
-        if openssl_version >= 0x1_01_02_00_0 {
+        if openssl_version >= 0x3_00_00_00_0 {
+            // OpenSSL 3.x - treat as OpenSSL 1.1.x compatible
+            println!("cargo:version=111");
+            Version::Openssl11x
+        } else if openssl_version >= 0x1_01_02_00_0 {
             version_error()
         } else if openssl_version >= 0x1_01_01_00_0 {
             println!("cargo:version=111");
