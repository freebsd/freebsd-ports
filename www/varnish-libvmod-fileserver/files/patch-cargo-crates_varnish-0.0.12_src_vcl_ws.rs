--- cargo-crates/varnish-0.0.12/src/vcl/ws.rs.orig	2023-01-08 02:53:56 UTC
+++ cargo-crates/varnish-0.0.12/src/vcl/ws.rs
@@ -10,6 +10,7 @@
 //! **Note:** unless you know what you are doing, you should probably just use the automatic type
 //! conversion provided by [`crate::vcl::convert`], or store things in
 //! [`crate::vcl::vpriv::VPriv`].
+use std::os::raw::c_char;
 use std::ffi::c_void;
 use std::ptr;
 use std::slice::from_raw_parts_mut;
@@ -213,7 +214,7 @@ impl<'a> Drop for ReservedBuf<'a> {
 pub struct TestWS {
     c_ws: varnish_sys::ws,
     #[allow(dead_code)]
-    space: Vec<i8>,
+    space: Vec<c_char>,
 }
 
 impl TestWS {
@@ -229,7 +230,7 @@ impl TestWS {
         TestWS {
             c_ws: varnish_sys::ws {
                 magic: varnish_sys::WS_MAGIC,
-                id: ['t' as i8, 's' as i8, 't' as i8, '\0' as i8],
+                id: ['t' as c_char, 's' as c_char, 't' as c_char, '\0' as c_char],
                 s,
                 f: s,
                 r: ptr::null_mut(),
