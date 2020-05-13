--- cargo-crates/rustls-native-certs-0.1.0/src/lib.rs.orig	2020-01-30 08:27:02 UTC
+++ cargo-crates/rustls-native-certs-0.1.0/src/lib.rs
@@ -4,9 +4,9 @@
 //! It consists of a single function [load_native_certs](fn.load_native_certs.html) which returns a
 //! `rustls::RootCertStore` pre-filled from the native certificate store.
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 mod linux;
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 use linux as platform;
 
 #[cfg(target_family = "windows")]
