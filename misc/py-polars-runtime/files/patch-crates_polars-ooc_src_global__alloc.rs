--- crates/polars-ooc/src/global_alloc.rs.orig	2026-04-09 13:00:26 UTC
+++ crates/polars-ooc/src/global_alloc.rs
@@ -42,6 +42,7 @@ fn update_alloc_size(bytes: i64) {
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 static UNDERLYING_ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
 
@@ -51,7 +52,7 @@ static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc
 ))]
 static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc::MiMalloc;
 
-#[cfg(not(feature = "fast_alloc"))]
+#[cfg(any(not(feature = "fast_alloc"), target_os = "freebsd"))]
 static UNDERLYING_ALLOC: std::alloc::System = std::alloc::System;
 
 pub struct Allocator;
