--- crates/main/src/main.rs.orig        2025-01-28 10:05:42 UTC
+++ crates/main/src/main.rs
@@ -16,10 +16,10 @@ use utils::wait_for_shutdown;
 use trc::Collector;
 use utils::wait_for_shutdown;
 
-#[cfg(not(target_env = "msvc"))]
+#[cfg(not(target_os = "freebsd"))]
 use jemallocator::Jemalloc;
 
-#[cfg(not(target_env = "msvc"))]
+#[cfg(not(target_os = "freebsd"))]
 #[global_allocator]
 static GLOBAL: Jemalloc = Jemalloc;
 
