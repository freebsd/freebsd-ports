Accept the system libdeflate 1.25 (this crate bundles 1.25 but asks
pkg-config for exactly 1.24, so it would silently fall back to the
bundled copy).

--- cargo-crates/libdeflate-sys-1.25.2/build.rs.orig	2026-10-03 04:08:53 UTC
+++ cargo-crates/libdeflate-sys-1.25.2/build.rs
@@ -9,7 +9,7 @@ fn main() {
     if pkg_config::Config::new()
         .print_system_libs(false)
         .cargo_metadata(true)
-        .exactly_version("1.24")
+        .atleast_version("1.25")
         .probe("libdeflate")
         .is_ok()
     {
