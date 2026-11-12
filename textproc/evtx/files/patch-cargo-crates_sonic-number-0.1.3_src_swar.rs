--- cargo-crates/sonic-number-0.1.3/src/swar.rs.orig	2026-11-01 10:13:27 UTC
+++ cargo-crates/sonic-number-0.1.3/src/swar.rs
@@ -1,18 +1,15 @@
-/// SWAR (SIMD Within A Register) integer parsing.
-///
-/// Based on simdjson's `parse_eight_digits_unrolled` technique.
-/// Uses pure u64 arithmetic to process 8 ASCII digits at a time.
-/// Requires little-endian byte order — the u64 load must place the first
-/// string byte in the least-significant byte position.
+//! SWAR (SIMD Within A Register) integer parsing.
+//!
+//! Based on simdjson's `parse_eight_digits_unrolled` technique.
+//! Uses pure u64 arithmetic to process 8 ASCII digits at a time.
+//! The 8-byte loads are converted from little-endian so that the first string
+//! byte lands in the least-significant byte position on every target.
 
-#[cfg(target_endian = "big")]
-compile_error!("SWAR digit parsing requires little-endian byte order");
-
 /// Check if 8 consecutive bytes are all ASCII digits ('0'-'9').
 #[inline(always)]
 pub fn is_eight_digits(src: &[u8]) -> bool {
     debug_assert!(src.len() >= 8);
-    let val = unsafe { core::ptr::read_unaligned(src.as_ptr() as *const u64) };
+    let val = u64::from_le(unsafe { core::ptr::read_unaligned(src.as_ptr() as *const u64) });
     let a = val.wrapping_add(0x4646464646464646); // 0x80 - '9' - 1
     let b = val.wrapping_sub(0x3030303030303030); // - '0'
     (a | b) & 0x8080808080808080 == 0
@@ -31,7 +28,7 @@ pub fn parse_eight_digits(src: &[u8]) -> u32 {
 #[inline(always)]
 pub fn parse_eight_digits(src: &[u8]) -> u32 {
     debug_assert!(src.len() >= 8);
-    let mut val = unsafe { core::ptr::read_unaligned(src.as_ptr() as *const u64) };
+    let mut val = u64::from_le(unsafe { core::ptr::read_unaligned(src.as_ptr() as *const u64) });
     val -= 0x3030303030303030;
     val = (val.wrapping_mul(10).wrapping_add(val >> 8)) & 0x00FF00FF00FF00FF;
     val = (val.wrapping_mul(100).wrapping_add(val >> 16)) & 0x0000FFFF0000FFFF;
@@ -77,7 +74,7 @@ pub unsafe fn parse_digits_tolerant(src: &[u8]) -> (u6
 #[inline(always)]
 pub unsafe fn parse_digits_tolerant(src: &[u8]) -> (u64, usize) {
     debug_assert!(src.len() >= 8);
-    let val = core::ptr::read_unaligned(src.as_ptr() as *const u64);
+    let val = u64::from_le(core::ptr::read_unaligned(src.as_ptr() as *const u64));
 
     let a = val.wrapping_add(0x4646464646464646);
     let b = val.wrapping_sub(0x3030303030303030);
