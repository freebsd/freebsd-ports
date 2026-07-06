--- cargo-crates/netwatch-0.18.0/src/interfaces/bsd/freebsd.rs.orig	2026-06-12 13:12:37 UTC
+++ cargo-crates/netwatch-0.18.0/src/interfaces/bsd/freebsd.rs
@@ -203,9 +203,9 @@ mod arm {
 }
 
 // Hardcoded based on the generated values here: https://cs.opensource.google/go/x/net/+/master:route/zsys_freebsd_arm.go
-#[cfg(target_arch = "aarch64")]
+#[cfg(any(target_arch = "aarch64", target_arch = "powerpc64", target_arch = "riscv64"))]
 pub use self::arm64::*;
-#[cfg(target_arch = "aarch64")]
+#[cfg(any(target_arch = "aarch64", target_arch = "powerpc64", target_arch = "riscv64"))]
 mod arm64 {
     pub const SIZEOF_IF_MSGHDRL_FREE_BSD10: usize = 0xb0;
     pub const SIZEOF_IFA_MSGHDR_FREE_BSD10: usize = 0x14;
