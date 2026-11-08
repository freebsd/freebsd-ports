--- src/cli/plugin.rs.orig	2026-09-29 14:11:37 UTC
+++ src/cli/plugin.rs
@@ -1539,7 +1539,8 @@ fn current_plugin_platform() -> PluginPlatform {
 }
 
 fn current_plugin_platform() -> PluginPlatform {
-    if cfg!(target_os = "linux") {
+    // FreeBSD runs the same Unix/XDG tooling Linux plugins expect.
+    if cfg!(any(target_os = "linux", target_os = "freebsd")) {
         PluginPlatform::Linux
     } else if cfg!(target_os = "macos") {
         PluginPlatform::Macos
