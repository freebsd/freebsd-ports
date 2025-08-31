https://chromium.googlesource.com/chromium/src/+/8393b61ba876c8e1614275c97767f9b06b889f48
https://chromium.googlesource.com/chromium/src/+/6aae0e2353c857d98980ff677bf304288d7c58de

--- build/rust/allocator/lib.rs.orig	2025-06-18 14:17:42.000000000 +0200
+++ build/rust/allocator/lib.rs	2025-08-24 10:57:12.002293000 +0200
@@ -89,9 +89,8 @@ mod both_allocators {
     /// As part of rustc's contract for using `#[global_allocator]` without
     /// rustc-generated shims we must define this symbol, since we are opting in
     /// to unstable functionality. See https://github.com/rust-lang/rust/issues/123015
-    #[no_mangle]
-    #[linkage = "weak"]
-    static __rust_no_alloc_shim_is_unstable: u8 = 0;
+    #[rustc_std_internal_symbol]
+    fn __rust_no_alloc_shim_is_unstable_v2() {}
 
     // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
