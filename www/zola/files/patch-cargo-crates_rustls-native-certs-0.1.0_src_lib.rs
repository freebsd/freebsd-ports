https://github.com/ctz/rustls-native-certs/commit/aebfc6e366c6b2a09b0d3b373fd51c6729d6b4b6

--- cargo-crates/rustls-native-certs-0.1.0/src/lib.rs.orig	2020-02-17 14:04:35 UTC
+++ cargo-crates/rustls-native-certs-0.1.0/src/lib.rs
@@ -4,9 +4,9 @@
 //! It consists of a single function [load_native_certs](fn.load_native_certs.html) which returns a
 //! `rustls::RootCertStore` pre-filled from the native certificate store.
 
-#[cfg(target_os = "linux")]
+#[cfg(all(unix, not(target_os = "macos")))]
 mod linux;
-#[cfg(target_os = "linux")]
+#[cfg(all(unix, not(target_os = "macos")))]
 use linux as platform;
 
 #[cfg(target_family = "windows")]
