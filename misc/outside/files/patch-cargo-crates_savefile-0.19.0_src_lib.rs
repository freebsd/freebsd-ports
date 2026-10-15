--- cargo-crates/savefile-0.19.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/savefile-0.19.0/src/lib.rs
@@ -1184,8 +1184,12 @@ impl IsPacked {
     /// a repr_c_optimization_safe-implementation is forbidden.
     ///
     /// Also, see description of Packed trait and repr_c_optimization_safe.
+    ///
+    /// The savefile disk format is little endian, so on big-endian hosts
+    /// the in-memory representation of multi-byte types never matches it
+    /// and the optimization is never allowed: there this returns `no()`.
     pub unsafe fn yes() -> IsPacked {
-        IsPacked(true)
+        IsPacked(cfg!(target_endian = "little"))
     }
     /// No, the type is not compatible with the "Packed"-optimization.
     /// It cannot be just blitted.
@@ -6144,10 +6148,6 @@ impl Deserialize for chrono::DateTime<chrono::Utc> {
 
 
 
-#[cfg(any(feature = "bit-vec", feature = "bit-vec08"))]
-#[cfg(target_endian = "big")]
-compile_error!("savefile bit-vec feature does not support big-endian machines");
-
 #[cfg(feature = "bit-vec")]
 impl WithSchema for bit_vec::BitVec {
     fn schema(version: u32, context: &mut WithSchemaContext) -> Schema {
@@ -6204,10 +6204,16 @@ impl Serialize for bit_vec::BitVec<u32> {
         let l = self.len();
         serializer.write_usize(l)?;
         let storage = self.storage();
-        let rawbytes_ptr = storage.as_ptr() as *const u8;
-        let rawbytes: &[u8] = unsafe { std::slice::from_raw_parts(rawbytes_ptr, 4 * storage.len()) };
-        serializer.write_usize(rawbytes.len() | (1 << 63))?;
-        serializer.write_bytes(rawbytes)?;
+        serializer.write_usize((4 * storage.len()) | (1 << 63))?;
+        if cfg!(target_endian = "little") {
+            let rawbytes_ptr = storage.as_ptr() as *const u8;
+            let rawbytes: &[u8] = unsafe { std::slice::from_raw_parts(rawbytes_ptr, 4 * storage.len()) };
+            serializer.write_bytes(rawbytes)?;
+        } else {
+            for word in storage {
+                serializer.write_u32(*word)?;
+            }
+        }
         Ok(())
     }
 }
@@ -6231,6 +6237,11 @@ impl Deserialize for bit_vec::BitVec<u32> {
                 let storage_ptr = storage.as_ptr() as *mut u8;
                 let storage_bytes: &mut [u8] = std::slice::from_raw_parts_mut(storage_ptr, 4 * num_words);
                 deserializer.read_bytes_to_buf(storage_bytes)?;
+                if cfg!(target_endian = "big") {
+                    for word in storage.iter_mut() {
+                        *word = u32::from_le(*word);
+                    }
+                }
                 ret.set_len(numbits);
             }
             Ok(ret)
@@ -6370,10 +6381,16 @@ impl Serialize for bit_vec08::BitVec<u32> {
         let l = self.len();
         serializer.write_usize(l)?;
         let storage = self.storage();
-        let rawbytes_ptr = storage.as_ptr() as *const u8;
-        let rawbytes: &[u8] = unsafe { std::slice::from_raw_parts(rawbytes_ptr, 4 * storage.len()) };
-        serializer.write_usize(rawbytes.len() | (1 << 63))?;
-        serializer.write_bytes(rawbytes)?;
+        serializer.write_usize((4 * storage.len()) | (1 << 63))?;
+        if cfg!(target_endian = "little") {
+            let rawbytes_ptr = storage.as_ptr() as *const u8;
+            let rawbytes: &[u8] = unsafe { std::slice::from_raw_parts(rawbytes_ptr, 4 * storage.len()) };
+            serializer.write_bytes(rawbytes)?;
+        } else {
+            for word in storage {
+                serializer.write_u32(*word)?;
+            }
+        }
         Ok(())
     }
 }
@@ -6397,6 +6414,11 @@ impl Deserialize for bit_vec08::BitVec<u32> {
                 let storage_ptr = storage.as_ptr() as *mut u8;
                 let storage_bytes: &mut [u8] = std::slice::from_raw_parts_mut(storage_ptr, 4 * num_words);
                 deserializer.read_bytes_to_buf(storage_bytes)?;
+                if cfg!(target_endian = "big") {
+                    for word in storage.iter_mut() {
+                        *word = u32::from_le(*word);
+                    }
+                }
                 ret.set_len(numbits);
             }
             Ok(ret)
