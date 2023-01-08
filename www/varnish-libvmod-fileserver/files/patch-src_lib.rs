--- src/lib.rs.orig	2023-01-08 03:03:24 UTC
+++ src/lib.rs
@@ -5,7 +5,7 @@ use std::collections::HashMap;
 use std::collections::hash_map::DefaultHasher;
 use std::hash::{Hash, Hasher};
 use std::io::{BufRead, BufReader, Read};
-use std::os::raw::{c_uint, c_void};
+use std::os::raw::{c_char, c_uint, c_void};
 use std::os::unix::fs::MetadataExt;
 use std::ptr;
 
@@ -113,7 +113,7 @@ impl root {
                 ctx.raw,
                 &METHODS.methods,
                 info_ptr as *mut std::ffi::c_void,
-                format!("{}\0", vcl_name).as_ptr() as *const i8,
+                format!("{}\0", vcl_name).as_ptr() as *const c_char,
             )
         };
 
@@ -170,7 +170,7 @@ struct VfpWrapper {
 }
 static FILE_VFP: VfpWrapper = VfpWrapper {
     vfp: varnish_sys::vfp {
-        name: "fileserver\0".as_ptr() as *const i8,
+        name: "fileserver\0".as_ptr() as *const c_char,
         init: None,
         pull: Some(varnish::vcl::processor::wrap_vfp_pull::<BackendResp>),
         fini: Some(varnish::vcl::processor::wrap_vfp_fini::<BackendResp>),
@@ -233,7 +233,7 @@ unsafe extern "C" fn be_gethdrs(
         );
 
         if (*bo.req).req_body_status != varnish_sys::BS_CACHED.as_ptr() {
-            bo.no_retry = "req.body not cached\0".as_ptr() as *const i8;
+            bo.no_retry = "req.body not cached\0".as_ptr() as *const c_char;
         }
 
         if (*bo.req).req_body_status == varnish_sys::BS_ERROR.as_ptr() {
