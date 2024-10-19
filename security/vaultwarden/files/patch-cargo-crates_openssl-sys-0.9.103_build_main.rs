--- cargo-crates/openssl-sys-0.9.103/build/main.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-sys-0.9.103/build/main.rs
@@ -379,6 +379,7 @@ See rust-openssl documentation for more information:
             (3, 8, _) => ('3', '8', 'x'),
             (3, 9, 0) => ('3', '9', '0'),
             (3, 9, _) => ('3', '9', 'x'),
+            (4, 0, _) => ('3', '9', 'x'),
             _ => version_error(),
         };
 
