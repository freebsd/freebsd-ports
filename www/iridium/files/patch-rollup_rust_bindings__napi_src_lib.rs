--- rollup/rust/bindings_napi/src/lib.rs.orig	2026-08-13 16:48:13 UTC
+++ rollup/rust/bindings_napi/src/lib.rs
@@ -8,6 +8,7 @@ use std::mem;
   not(all(target_os = "linux", target_arch = "riscv64", target_env = "musl")),
   not(all(target_os = "linux", target_env = "ohos")),
   not(all(target_os = "freebsd", target_arch = "aarch64")),
+  not(all(target_os = "openbsd", target_arch = "aarch64")),
   not(debug_assertions)
 ))]
 #[global_allocator]
