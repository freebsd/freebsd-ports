--- src/app/api/plugins/manifest.rs.orig	2026-09-29 14:11:38 UTC
+++ src/app/api/plugins/manifest.rs
@@ -506,7 +506,8 @@ fn current_platform() -> PluginPlatform {
 
 /// Returns the platform the current binary was compiled for.
 fn current_platform() -> PluginPlatform {
-    if cfg!(target_os = "linux") {
+    // FreeBSD runs the same Unix/XDG tooling Linux plugins expect.
+    if cfg!(any(target_os = "linux", target_os = "freebsd")) {
         PluginPlatform::Linux
     } else if cfg!(target_os = "macos") {
         PluginPlatform::Macos
