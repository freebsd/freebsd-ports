--- cargo-crates/sonic-simd-0.1.4/src/v256.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sonic-simd-0.1.4/src/v256.rs
@@ -26,14 +26,7 @@ impl Mask for Mask256 {
                 unsafe { super::neon::to_bitmask32(v0.0, v1.0) }
             } else {
                 fn combine_u16(lo: u16, hi: u16) -> u32 {
-                    #[cfg(target_endian = "little")]
-                    {
-                        (lo as u32) | ((hi as u32) << 16)
-                    }
-                    #[cfg(target_endian = "big")]
-                    {
-                        (hi as u32) | ((lo as u32) << 16)
-                    }
+                    (lo as u32) | ((hi as u32) << 16)
                 }
                 combine_u16(self.0 .0.bitmask(), self.0 .1.bitmask())
             }
