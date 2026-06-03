--- rollup/rust/bindings_napi/src/lib.rs.orig	2026-02-11 09:05:39 UTC
+++ rollup/rust/bindings_napi/src/lib.rs
@@ -4,6 +4,8 @@ use parse_ast::parse_ast;
 
 #[cfg(all(
   not(all(target_os = "linux", target_env = "musl", target_arch = "aarch64")),
+  not(all(target_os = "freebsd", target_arch = "aarch64")),
+  not(all(target_os = "openbsd", target_arch = "aarch64")),
   not(debug_assertions)
 ))]
 #[global_allocator]
