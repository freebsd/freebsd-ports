Index: cli/tools/bundle/esbuild.rs
--- cli/tools/bundle/esbuild.rs.orig
+++ cli/tools/bundle/esbuild.rs
@@ -22,10 +22,14 @@ pub const ESBUILD_VERSION: &str = "0.25.5";
 
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
     _ => panic!(
