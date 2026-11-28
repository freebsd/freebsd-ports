--- crates/polars-ooc/src/dirty_limit.rs.orig	2026-11-28 13:01:57 UTC
+++ crates/polars-ooc/src/dirty_limit.rs
@@ -8,7 +8,7 @@
 #[cfg(all(
     feature = "fast_alloc",
     target_family = "unix",
-    not(target_os = "emscripten"),
+    not(any(target_os = "emscripten", target_os = "freebsd")),
 ))]
 mod jemalloc {
     use std::ffi::c_void;
@@ -67,13 +67,13 @@ mod jemalloc {
 #[cfg(all(
     feature = "fast_alloc",
     target_family = "unix",
-    not(target_os = "emscripten"),
+    not(any(target_os = "emscripten", target_os = "freebsd")),
 ))]
 pub(crate) use jemalloc::install;
 
 #[cfg(not(all(
     feature = "fast_alloc",
     target_family = "unix",
-    not(target_os = "emscripten"),
+    not(any(target_os = "emscripten", target_os = "freebsd")),
 )))]
 pub(crate) fn install() {}
