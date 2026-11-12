--- cargo-crates/sonic-simd-0.1.4/src/v128.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sonic-simd-0.1.4/src/v128.rs
@@ -108,20 +108,11 @@ impl Mask for Mask128 {
     type Element = u8;
 
     fn bitmask(self) -> Self::BitMask {
-        #[cfg(target_endian = "little")]
-        {
-            self.0
-                .iter()
-                .enumerate()
-                .fold(0, |acc, (i, &b)| acc | ((b as u16) << i))
-        }
-        #[cfg(target_endian = "big")]
-        {
-            self.0
-                .iter()
-                .enumerate()
-                .fold(0, |acc, (i, &b)| acc | ((b as u16) << (15 - i)))
-        }
+        // Lane `i` is bit `i`, like `movemask` on x86, on every target.
+        self.0
+            .iter()
+            .enumerate()
+            .fold(0, |acc, (i, &b)| acc | ((b as u16) << i))
     }
 
     fn splat(b: bool) -> Self {
