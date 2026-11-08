Index: cli/tools/bundle/esbuild.rs
--- cli/tools/bundle/esbuild.rs.orig	2026-09-16 15:45:55 UTC
+++ cli/tools/bundle/esbuild.rs
@@ -25,10 +25,14 @@ fn esbuild_platform() -> &'static str {
 
 fn esbuild_platform() -> &'static str {
   match (std::env::consts::ARCH, std::env::consts::OS) {
+    ("x86_64", "freebsd") => "freebsd-x64",
+    ("aarch64", "freebsd") => "freebsd-arm64",
     ("x86_64", "linux") => "linux-x64",
     ("aarch64", "linux") => "linux-arm64",
     ("x86_64", "macos" | "apple") => "darwin-x64",
     ("aarch64", "macos" | "apple") => "darwin-arm64",
+    ("x86_64", "openbsd") => "openbsd-x64",
+    ("aarch64", "openbsd") => "openbsd-arm64",
     ("x86_64", "windows") => "win32-x64",
     ("aarch64", "windows") => "win32-arm64",
     ("x86_64", "android") => "android-x64",
