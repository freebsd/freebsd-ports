--- build/rust/allocator/lib.rs.orig	1970-01-01 00:00:00 UTC
+++ build/rust/allocator/lib.rs
@@ -111,6 +111,12 @@ mod both_allocators {
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
