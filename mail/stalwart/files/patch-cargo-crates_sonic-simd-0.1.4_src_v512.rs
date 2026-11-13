--- cargo-crates/sonic-simd-0.1.4/src/v512.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sonic-simd-0.1.4/src/v512.rs
@@ -28,14 +28,7 @@ impl Mask for Mask512 {
                 unsafe { super::neon::to_bitmask64(m0.0, m1.0, m2.0, m3.0) }
             } else {
                 fn combine_u32(lo: u32, hi: u32) -> u64 {
-                    #[cfg(target_endian = "little")]
-                    {
-                        (lo as u64) | ((hi as u64) << 32)
-                    }
-                    #[cfg(target_endian = "big")]
-                    {
-                        (hi as u64) | ((lo as u64) << 32)
-                    }
+                    (lo as u64) | ((hi as u64) << 32)
                 }
                 combine_u32(self.0 .0.bitmask(), self.0 .1.bitmask())
             }
