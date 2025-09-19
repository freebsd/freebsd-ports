--- crates/polars-python/src/c_api/allocator.rs.orig	2025-09-18 08:58:22 UTC
+++ crates/polars-python/src/c_api/allocator.rs
@@ -2,6 +2,7 @@
     not(feature = "default_alloc"),
     target_family = "unix",
     not(target_os = "emscripten"),
+    not(target_os = "freebsd"),
 ))]
 #[global_allocator]
 static ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
