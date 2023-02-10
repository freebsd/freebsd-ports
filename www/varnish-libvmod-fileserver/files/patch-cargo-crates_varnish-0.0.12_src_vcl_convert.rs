--- cargo-crates/varnish-0.0.12/src/vcl/convert.rs.orig	2023-01-08 01:32:37 UTC
+++ cargo-crates/varnish-0.0.12/src/vcl/convert.rs
@@ -139,9 +139,9 @@ impl IntoVCL<VCL_STRING> for &[u8] {
         // try to save some work if the buffer is already in the workspace
         // and if it's followed by a null byte
         if unsafe { varnish_sys::WS_Allocated(ws.raw, self.as_ptr() as *const c_void, self.len() as i64 + 1) == 1 && *self.as_ptr().add(self.len()) == b'\0' } {
-            Ok(self.as_ptr() as *const i8)
+            Ok(self.as_ptr() as *const c_char)
         } else {
-            Ok(ws.copy_bytes_with_null(&self)?.as_ptr() as *const i8)
+            Ok(ws.copy_bytes_with_null(&self)?.as_ptr() as *const c_char)
         }
     }
 }
