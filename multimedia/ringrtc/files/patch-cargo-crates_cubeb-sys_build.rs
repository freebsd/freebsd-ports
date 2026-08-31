--- cargo-crates/cubeb-sys-0.36.0/build.rs.orig	2025-02-01 09:46:43 UTC
+++ cargo-crates/cubeb-sys-0.36.0/build.rs
@@ -203,19 +203,6 @@ fn main() {
         // Ignore the result of find_library. We don't care if the
         // libraries are missing.
         let _ = pkg_config::find_library("alsa");
-        if pkg_config::find_library("libpulse").is_ok() {
-            // Do not link the rust backends for tests: doing so causes duplicate
-            // symbol definitions.
-            if build_rust_libs {
-                println!("cargo:rustc-link-lib=static=cubeb_pulse");
-                // The nested build's profile subdir (debug vs release) follows the
-                // CMake build type, which is derived from opt-level and can differ
-                // from this crate's PROFILE; search both so either one lands the lib.
-                for profile in ["debug", "release"] {
-                    println!("cargo:rustc-link-search=native={rust_target_dir}/{target}/{profile}");
-                }
-            }
-        }
         let _ = pkg_config::find_library("jack");
         let _ = pkg_config::find_library("speexdsp");
         if android {
