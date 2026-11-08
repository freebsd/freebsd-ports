-- Set the auto-launch executable path on FreeBSD.
-- Without this the plugin setup left the path unset on FreeBSD.
--- cargo-crates/tauri-plugin-autostart-2.5.1/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tauri-plugin-autostart-2.5.1/src/lib.rs
@@ -222,6 +222,9 @@ impl Builder {
                     builder.set_app_path(&current_exe.display().to_string());
                 }
 
+                #[cfg(target_os = "freebsd")]
+                builder.set_app_path(&current_exe.display().to_string());
+
                 app.manage(AutoLaunchManager(
                     builder.build().map_err(|e| e.to_string())?,
                 ));
