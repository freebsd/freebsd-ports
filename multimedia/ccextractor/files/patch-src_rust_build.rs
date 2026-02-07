--- src/rust/build.rs.orig	2026-01-05 15:05:24 UTC
+++ src/rust/build.rs
@@ -69,6 +69,7 @@ fn main() {
         "eia608_screen",
         "uint8_t",
         "word_list",
+	"iconv_t",
     ]);
 
     #[cfg(feature = "hardsubx_ocr")]
@@ -115,7 +116,7 @@ fn main() {
         }
 
         // On Linux, try pkg-config to find FFmpeg include paths
-        if cfg!(target_os = "linux") {
+        if cfg!(any(target_os = "linux", target_os = "freebsd")) {
             if let Ok(lib) = pkg_config::Config::new().probe("libavcodec") {
                 for path in lib.include_paths {
                     builder = builder.clang_arg(format!("-I{}", path.display()));
