--- cargo-crates/tun-0.6.1/src/platform/mod.rs.orig	2024-01-02 20:10:59 UTC
+++ cargo-crates/tun-0.6.1/src/platform/mod.rs
@@ -22,6 +22,11 @@ pub use self::linux::{create, Configuration, Device, Q
 #[cfg(target_os = "linux")]
 pub use self::linux::{create, Configuration, Device, Queue};
 
+#[cfg(target_os = "freebsd")]
+pub mod freebsd;
+#[cfg(target_os = "freebsd")]
+pub use self::freebsd::{create, Configuration, Device, Queue};
+
 #[cfg(target_os = "macos")]
 pub mod macos;
 #[cfg(target_os = "macos")]
