--- cargo-crates/cubeb-sys-0.30.1/build.rs.orig	2025-02-01 09:46:43 UTC
+++ cargo-crates/cubeb-sys-0.30.1/build.rs
@@ -155,22 +155,6 @@ fn main() {
         // Ignore the result of find_library. We don't care if the
         // libraries are missing.
         let _ = pkg_config::find_library("alsa");
-        if pkg_config::find_library("libpulse").is_ok() {
-            // Do not link the rust backends for tests: doing so causes duplicate
-            // symbol definitions.
-            if build_rust_libs {
-                println!("cargo:rustc-link-lib=static=cubeb_pulse");
-                let mut search_path = std::env::current_dir().unwrap();
-                search_path.push(&(libcubeb_path + "/src/cubeb-pulse-rs/target"));
-                search_path.push(&target);
-                if debug {
-                    search_path.push("debug");
-                } else {
-                    search_path.push("release");
-                }
-                println!("cargo:rustc-link-search=native={}", search_path.display());
-            }
-        }
         let _ = pkg_config::find_library("jack");
         let _ = pkg_config::find_library("speexdsp");
         if android {
