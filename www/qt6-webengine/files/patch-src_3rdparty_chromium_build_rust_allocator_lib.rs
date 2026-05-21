--- src/3rdparty/chromium/build/rust/allocator/lib.rs.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/build/rust/allocator/lib.rs
@@ -91,6 +91,12 @@ mod both_allocators {
     #[linkage = "weak"]
     fn __rust_no_alloc_shim_is_unstable_v2() {}
 
+    // TODO(crbug.com/422538133) Remove after rolling past
+    // https://github.com/rust-lang/rust/pull/141061
+    #[no_mangle]
+    #[linkage = "weak"]
+    static __rust_no_alloc_shim_is_unstable: u8 = 0;
+
     // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
