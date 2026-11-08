--- cargo-crates/datasketches-0.2.0/src/hash/murmurhash.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/datasketches-0.2.0/src/hash/murmurhash.rs
@@ -164,6 +164,32 @@ impl Hasher for MurmurHash3X64128 {
             self.buf_len = len;
         }
     }
+
+    // The default implementations of the fixed-width methods hash the
+    // native-endian bytes of the integer, which would make the hash of an
+    // integer depend on the byte order of the host. Always hash the
+    // little-endian representation so that sketches built on big-endian
+    // hosts are identical to those built on little-endian hosts (and to
+    // those built by the Java and C++ implementations).
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
 
 /// Finalization mix: force all bits of a hash block to avalanche.
