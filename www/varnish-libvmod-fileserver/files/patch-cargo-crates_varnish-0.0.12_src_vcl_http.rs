--- cargo-crates/varnish-0.0.12/src/vcl/http.rs.orig	2023-01-08 02:38:57 UTC
+++ cargo-crates/varnish-0.0.12/src/vcl/http.rs
@@ -12,7 +12,7 @@
 //! this [issue](https://github.com/gquintard/varnish-rs/issues/4).
 
 #![allow(clippy::not_unsafe_ptr_arg_deref)]
-use std::os::raw::c_uint;
+use std::os::raw::{c_char, c_uint};
 use std::slice::{from_raw_parts, from_raw_parts_mut};
 use std::str::from_utf8;
 
@@ -53,9 +53,9 @@ impl<'a> HTTP<'a> {
         let hdr_buf = ws.copy_bytes_with_null(&value)?;
         unsafe {
             let mut hd = self.raw.hd.offset(idx as isize);
-            (*hd).b = hdr_buf.as_ptr() as *const i8;
+            (*hd).b = hdr_buf.as_ptr() as *const c_char;
             /* -1 accounts for the null character */
-            (*hd).e = hdr_buf.as_ptr().add(hdr_buf.len() - 1) as *const i8;
+            (*hd).e = hdr_buf.as_ptr().add(hdr_buf.len() - 1) as *const c_char;
             let hdf = self.raw.hdf.offset(idx as isize);
             *hdf = 0;
         }
