-- Use the Linux DBus single-instance implementation on FreeBSD.
-- The plugin had no FreeBSD platform module.
--- cargo-crates/tauri-plugin-single-instance-2.3.6/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tauri-plugin-single-instance-2.3.6/src/lib.rs
@@ -15,7 +15,7 @@ mod platform_impl;
 #[cfg(target_os = "windows")]
 #[path = "platform_impl/windows.rs"]
 mod platform_impl;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[path = "platform_impl/linux.rs"]
 mod platform_impl;
 #[cfg(target_os = "macos")]
