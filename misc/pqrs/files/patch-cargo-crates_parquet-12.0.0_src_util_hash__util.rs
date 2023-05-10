--- cargo-crates/parquet-12.0.0/src/util/hash_util.rs.orig	2023-05-10 13:42:08 UTC
+++ cargo-crates/parquet-12.0.0/src/util/hash_util.rs
@@ -36,6 +36,8 @@ fn hash_(data: &[u8], seed: u32) -> u32 {
     #[cfg(any(
         target_arch = "aarch64",
         target_arch = "arm",
+        target_arch = "powerpc",
+        target_arch = "powerpc64",
         target_arch = "riscv64",
         target_arch = "wasm32"
     ))]
