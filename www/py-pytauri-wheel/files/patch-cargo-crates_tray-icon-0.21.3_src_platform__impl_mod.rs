-- Use the GTK platform implementation on FreeBSD.
-- tray-icon had no platform module for FreeBSD.
--- cargo-crates/tray-icon-0.21.3/src/platform_impl/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tray-icon-0.21.3/src/platform_impl/mod.rs
@@ -5,7 +5,7 @@ mod platform;
 #[cfg(target_os = "windows")]
 #[path = "windows/mod.rs"]
 mod platform;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[path = "gtk/mod.rs"]
 mod platform;
 #[cfg(target_os = "macos")]
