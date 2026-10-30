-- Disable jemalloc-specific pressure-decay logic on FreeBSD.
-- The jemalloc module imports tikv_jemalloc_sys, which is not available
-- in the FreeBSD build, so it must be compiled out on that platform.

--- crates/polars-ooc/src/decay.rs.orig	2026-10-25 14:18:24 UTC
+++ crates/polars-ooc/src/decay.rs
@@ -6,6 +6,7 @@
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 mod jemalloc {
     use std::ffi::{CStr, c_void};
@@ -470,6 +471,7 @@ mod jemalloc {
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 pub(crate) use jemalloc::note_spill;
 
@@ -477,5 +479,6 @@ pub(crate) use jemalloc::note_spill;
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 )))]
 pub(crate) fn note_spill() {}
