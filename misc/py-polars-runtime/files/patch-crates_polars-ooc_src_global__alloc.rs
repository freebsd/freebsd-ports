--- crates/polars-ooc/src/global_alloc.rs.orig	2026-10-06 06:15:22 UTC
+++ crates/polars-ooc/src/global_alloc.rs
@@ -66,6 +66,7 @@ fn oomkill() -> ! {
     feature = "fast_alloc",
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 static UNDERLYING_ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
 
@@ -75,7 +76,7 @@ static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc
 ))]
 static UNDERLYING_ALLOC: mimalloc::MiMalloc = mimalloc::MiMalloc;
 
-#[cfg(not(feature = "fast_alloc"))]
+#[cfg(any(not(feature = "fast_alloc"), target_os = "freebsd"))]
 static UNDERLYING_ALLOC: std::alloc::System = std::alloc::System;
 
 pub struct Allocator;
