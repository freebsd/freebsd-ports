--- cargo-crates/sonic-simd-0.1.4/src/bits.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sonic-simd-0.1.4/src/bits.rs
@@ -19,14 +19,9 @@ macro_rules! impl_bits {
 
                 #[inline]
                 fn as_little_endian(&self) -> Self {
-                    #[cfg(target_endian = "little")]
-                    {
-                        self.clone()
-                    }
-                    #[cfg(target_endian = "big")]
-                    {
-                        self.swap_bytes()
-                    }
+                    // Every backend builds its bitmask lane-ordered (lane `i` at bit `i`), so
+                    // there is nothing to convert, whatever the byte order of the target is.
+                    *self
                 }
 
                 #[inline]
