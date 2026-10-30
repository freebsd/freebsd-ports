-- Use the system allocator on FreeBSD instead of jemalloc.
-- This avoids both the broken tikv-jemalloc-sys build and runtime TLS
-- errors that occur when jemalloc is used as the global allocator.

--- crates/polars-ooc/src/global_alloc.rs.orig	2026-10-25 14:18:24 UTC
+++ crates/polars-ooc/src/global_alloc.rs
@@ -72,6 +72,7 @@ fn oomkill() -> ! {
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 static UNDERLYING_ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
 
@@ -81,7 +82,7 @@ static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc
 ))]
 static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc::MiMalloc;
 
-#[cfg(not(feature = "fast_alloc"))]
+#[cfg(any(not(feature = "fast_alloc"), target_os = "freebsd"))]
 static UNDERLYING_ALLOC: std::alloc::System = std::alloc::System;
 
 pub struct Allocator;
