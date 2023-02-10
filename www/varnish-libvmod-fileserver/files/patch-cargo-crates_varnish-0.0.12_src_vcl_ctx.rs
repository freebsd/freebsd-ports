--- cargo-crates/varnish-0.0.12/src/vcl/ctx.rs.orig	2023-01-08 01:41:36 UTC
+++ cargo-crates/varnish-0.0.12/src/vcl/ctx.rs
@@ -4,6 +4,7 @@ use std::os::raw::{c_uint, c_void};
 
 use crate::vcl::http::HTTP;
 use crate::vcl::ws::{TestWS, WS};
+use std::os::raw::c_char;
 use std::ptr;
 use varnish_sys::{
     busyobj, req, sess, vrt_ctx, vsb, vsl_log, ws, VSL_tag_e_SLT_Debug, VSL_tag_e_SLT_Error,
@@ -103,7 +104,7 @@ impl<'a> Ctx<'a> {
         // not great, we have to copy the string to add a null character
         let c_cstring = CString::new(msg).unwrap();
         unsafe {
-            VRT_fail(self.raw, "%s\0".as_ptr() as *const i8, c_cstring.as_ptr());
+            VRT_fail(self.raw, "%s\0".as_ptr() as *const c_char, c_cstring.as_ptr());
         }
         0
     }
@@ -116,8 +117,8 @@ impl<'a> Ctx<'a> {
                 log(logtag, msg);
             } else {
                 let t = varnish_sys::txt {
-                    b: msg.as_ptr() as *const i8,
-                    e: msg.as_ptr().add(msg.len()) as *const i8,
+                    b: msg.as_ptr() as *const c_char,
+                    e: msg.as_ptr().add(msg.len()) as *const c_char,
                 };
                 varnish_sys::VSLbt(p.vsl, logtag.into_u32(), t);
 
@@ -245,6 +246,6 @@ impl Event {
 pub fn log(logtag: LogTag, msg: &str) {
     unsafe {
         let c_cstring = CString::new(msg).unwrap();
-        varnish_sys::VSL(logtag.into_u32(), 0, b"%s\0".as_ptr() as *const i8, c_cstring.as_ptr() as *const u8);
+        varnish_sys::VSL(logtag.into_u32(), 0, b"%s\0".as_ptr() as *const c_char, c_cstring.as_ptr() as *const u8);
     }
 }
