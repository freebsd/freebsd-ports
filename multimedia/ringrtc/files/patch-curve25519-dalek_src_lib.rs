--- ../../../curve25519-dalek-4f0aa6653c51598daa0a2f53b8ba54ce0eedfbdd/src/lib.rs.orig	2023-07-12 11:09:23 UTC
+++ ../../../curve25519-dalek-4f0aa6653c51598daa0a2f53b8ba54ce0eedfbdd/src/lib.rs
@@ -15,7 +15,7 @@
 #![cfg_attr(feature = "simd_backend", feature(stdsimd))]
 
 // Refuse to compile if documentation is missing.
-#![deny(missing_docs)]
+//#![deny(missing_docs)]
 
 #![doc(html_logo_url = "https://doc.dalek.rs/assets/dalek-logo-clear.png")]
 #![doc(html_root_url = "https://docs.rs/curve25519-dalek/3.2.1")]
