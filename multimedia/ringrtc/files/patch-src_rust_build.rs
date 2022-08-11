--- build.rs.orig	2021-03-15 17:47:59 UTC
+++ build.rs
@@ -21,7 +21,9 @@ fn main() {
             println!("cargo:rustc-link-search=native=../../src/webrtc/src/out/Release/obj/",);
         }
 
-        if cfg!(target_os = "macos") {
+        if cfg!(target_os = "freebsd") {
+            println!("cargo:rustc-link-lib=dylib=c++");
+        } else if cfg!(target_os = "macos") {
             println!("cargo:rustc-link-lib=dylib=c++");
             println!("cargo:rustc-link-lib=framework=Foundation");
             println!("cargo:rustc-link-lib=framework=CoreAudio");
