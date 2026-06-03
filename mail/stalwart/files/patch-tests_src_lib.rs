--- tests/src/lib.rs.orig       2025-01-28 10:11:28 UTC
+++ tests/src/lib.rs
@@ -6,12 +6,12 @@ use std::path::PathBuf;
 
 use std::path::PathBuf;
 
-#[cfg(not(target_env = "msvc"))]
+#[cfg(not(target_os = "freebsd"))]
 use jemallocator::Jemalloc;
 #[cfg(test)]
 use trc::Collector;
 
-#[cfg(not(target_env = "msvc"))]
+#[cfg(not(target_os = "freebsd"))]
 #[global_allocator]
 static GLOBAL: Jemalloc = Jemalloc;
 
