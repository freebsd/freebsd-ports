Replace a failing build with a failing test: there is no prebuilt
typescript-go binary for OpenBSD, and the tsgo integration is disabled
in the cli. There's no point in having the build fail because of it,
however.

Index: tests/util/server/src/servers/mod.rs
--- tests/util/server/src/servers/mod.rs.orig
+++ tests/util/server/src/servers/mod.rs
@@ -1500,10 +1500,8 @@ const fn tsgo_platform() -> &'static str {
     (b"macos", b"aarch64") => "macos-arm64",
     (b"linux", b"x86_64") => "linux-x64",
     (b"linux", b"aarch64") => "linux-arm64",
-    _ => {
-      panic!("unsupported platform");
+    _ => "unknown-unknown"
     }
-  }
 }
 pub fn tsgo_prebuilt_path() -> PathRef {
   if let Ok(path) = std::env::var("DENO_TSGO_PATH") {
@@ -1513,7 +1511,7 @@ pub fn tsgo_prebuilt_path() -> PathRef {
     "linux" => "linux64",
     "windows" => "win",
     "macos" | "apple" => "mac",
-    _ => panic!("unsupported platform"),
+    _ => "unsupported-platform"
   };
   prebuilt_path().join(folder).join(format!(
     "tsgo-{}-{}",
