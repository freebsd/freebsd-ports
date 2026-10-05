-- Do not read env.appimage on FreeBSD.
-- The appimage field is Linux-only; FreeBSD has no AppImage support.
--- cargo-crates/tauri-plugin-updater-2.9.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tauri-plugin-updater-2.9.0/src/lib.rs
@@ -90,13 +90,7 @@ impl<R: Runtime, T: Manager<R>> UpdaterExt<R> for T {
 
         builder.version_comparator = version_comparator.clone();
 
-        #[cfg(any(
-            target_os = "linux",
-            target_os = "dragonfly",
-            target_os = "freebsd",
-            target_os = "netbsd",
-            target_os = "openbsd"
-        ))]
+        #[cfg(target_os = "linux")]
         {
             let env = app.env();
             if let Some(appimage) = env.appimage {
