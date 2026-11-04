--- cargo-crates/datasketches-0.2.0/src/hash/xxhash.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/datasketches-0.2.0/src/hash/xxhash.rs
@@ -165,6 +165,28 @@ impl Hasher for XxHash64 {
             self.buffer_len = remainder.len();
         }
     }
+
+    // See MurmurHash3X64128: hash integers as little-endian bytes so that
+    // the result does not depend on the byte order of the host.
+    fn write_u16(&mut self, i: u16) {
+        self.write(&i.to_le_bytes());
+    }
+
+    fn write_u32(&mut self, i: u32) {
+        self.write(&i.to_le_bytes());
+    }
+
+    fn write_u64(&mut self, i: u64) {
+        self.write(&i.to_le_bytes());
+    }
+
+    fn write_u128(&mut self, i: u128) {
+        self.write(&i.to_le_bytes());
+    }
+
+    fn write_usize(&mut self, i: usize) {
+        self.write(&i.to_le_bytes());
+    }
 }
 
 #[inline]
