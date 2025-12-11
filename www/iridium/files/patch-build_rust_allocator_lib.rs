--- build/rust/allocator/lib.rs.orig	2025-12-10 15:04:57 UTC
+++ build/rust/allocator/lib.rs
@@ -96,6 +96,12 @@ mod both_allocators {
         0
     }
 
+    // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
+    #[rustc_std_internal_symbol]
+    #[allow(non_upper_case_globals)]
+    #[linkage = "weak"]
+    static __rust_alloc_error_handler_should_panic: u8 = 0;
+
     // Mangle the symbol name as rustc expects.
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
