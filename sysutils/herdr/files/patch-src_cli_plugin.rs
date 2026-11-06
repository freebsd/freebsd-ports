--- src/cli/plugin.rs.orig	2026-10-14 15:56:41 UTC
+++ src/cli/plugin.rs
@@ -1723,7 +1723,8 @@ fn current_plugin_platform() -> PluginPlatform {
 }
 
 fn current_plugin_platform() -> PluginPlatform {
-    if cfg!(target_os = "linux") {
+    // FreeBSD runs the same Unix/XDG tooling Linux plugins expect.
+    if cfg!(any(target_os = "linux", target_os = "freebsd")) {
         PluginPlatform::Linux
     } else if cfg!(target_os = "macos") {
         PluginPlatform::Macos
