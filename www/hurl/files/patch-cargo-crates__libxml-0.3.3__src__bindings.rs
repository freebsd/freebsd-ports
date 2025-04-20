--- cargo-crates/libxml-0.3.3/src/bindings.rs.orig	2025-04-19 21:03:10 UTC
+++ cargo-crates/libxml-0.3.3/src/bindings.rs
@@ -5666,9 +5666,6 @@
   pub fn xmlSetGenericErrorFunc(ctx: *mut ::std::os::raw::c_void, handler: xmlGenericErrorFunc);
 }
 extern "C" {
-  pub fn initGenericErrorDefaultFunc(handler: *mut xmlGenericErrorFunc);
-}
-extern "C" {
   pub fn xmlSetStructuredErrorFunc(
     ctx: *mut ::std::os::raw::c_void,
     handler: xmlStructuredErrorFunc,
