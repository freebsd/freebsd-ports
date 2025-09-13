--- build/rust/allocator/lib.rs.orig	2025-09-11 13:19:19 UTC
+++ build/rust/allocator/lib.rs
@@ -90,6 +90,12 @@ mod both_allocators {
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
