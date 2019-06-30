--- vendor/openssl-sys/build/main.rs.orig	2018-12-22 10:43:42 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -505,6 +505,7 @@ See rust-openssl README for more information:
             (8, 1) => ('8', '1'),
             (8, _) => ('8', 'x'),
             (9, 0) => ('9', '0'),
+            (9, _) => ('9', 'x'),
             _ => version_error(),
         };
 
@@ -545,7 +546,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 2.9.0, but a different version of OpenSSL was found. The build is now aborting
+through 2.9.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
