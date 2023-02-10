--- cargo-crates/varnish-0.0.12/src/vcl/processor.rs.orig	2023-01-08 02:45:31 UTC
+++ cargo-crates/varnish-0.0.12/src/vcl/processor.rs
@@ -5,6 +5,7 @@
 //! *Note:* The rust wrapper here is pretty thin and the vmod writer will most probably need to have to
 //! deal with the raw Varnish internals.
 
+use std::os::raw::c_char;
 use std::os::raw::c_int;
 use std::os::raw::c_void;
 use std::ptr;
@@ -129,7 +130,7 @@ pub unsafe extern "C" fn gen_vdp_push<T: VDP>(
 /// Create a `varnish_sys::vdp` that can be fed to `varnish_sys::VRT_AddVDP`
 pub fn new_vdp<T: VDP>() -> varnish_sys::vdp {
     varnish_sys::vdp {
-        name: T::name().as_ptr() as *const i8,
+        name: T::name().as_ptr() as *const c_char,
         init: Some(gen_vdp_init::<T>),
         bytes: Some(gen_vdp_push::<T>),
         fini: Some(gen_vdp_fini::<T>),
@@ -246,7 +247,7 @@ pub unsafe extern "C" fn wrap_vfp_fini<T: VFP>(ctxp: *
 /// Create a `varnish_sys::vfp` that can be fed to `varnish_sys::VRT_AddVFP`
 pub fn new_vfp<T: VFP>() -> varnish_sys::vfp {
     varnish_sys::vfp {
-        name: T::name().as_ptr() as *const i8,
+        name: T::name().as_ptr() as *const c_char,
         init: Some(wrap_vfp_init::<T>),
         pull: Some(wrap_vfp_pull::<T>),
         fini: Some(wrap_vfp_fini::<T>),
