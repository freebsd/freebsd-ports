--- ext/node/ops/buffer.rs.orig	2026-09-16 15:45:55 UTC
+++ ext/node/ops/buffer.rs
@@ -399,7 +399,7 @@ fn decode_utf16le_from_bytes<'a>(
   // Fallback for big-endian architectures (uncommon environments).
   #[cfg(target_endian = "big")]
   {
-    let u16_data = buf
+    let u16_data: Vec<u16> = buf
       .chunks_exact(2)
       .map(|chunk| u16::from_le_bytes([chunk[0], chunk[1]]))
       .collect();
