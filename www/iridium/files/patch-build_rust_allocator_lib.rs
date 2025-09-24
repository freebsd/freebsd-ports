--- build/rust/allocator/lib.rs.orig	2025-09-10 13:22:16 UTC
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
https://issues.chromium.org/issues/440481922
https://chromium-review.googlesource.com/c/chromium/src/+/6875644


From 23d818d3c7fba4658248f17fd7b8993199242aa9 Mon Sep 17 00:00:00 2001
From: Hans Wennborg <hans@chromium.org>
Date: Fri, 22 Aug 2025 10:34:47 -0700
Subject: [PATCH] [rust] Define __rust_alloc_error_handler_should_panic_v2

https://github.com/rust-lang/rust/pull/143387 made
__rust_alloc_error_handler_should_panic a function.

The new definition is needed when rolling Rust past that PR. We can
remove the old symbol afterwards.

Bug: 440481922
Change-Id: I3340edd6d96d76de14942af67939978140430424
Reviewed-on: https://chromium-review.googlesource.com/c/chromium/src/+/6875644
Commit-Queue: Arthur Eubanks <aeubanks@google.com>
Reviewed-by: Arthur Eubanks <aeubanks@google.com>
Auto-Submit: Hans Wennborg <hans@chromium.org>
Commit-Queue: Hans Wennborg <hans@chromium.org>
Cr-Commit-Position: refs/heads/main@{#1505162}
---

diff --git a/build/rust/allocator/lib.rs b/build/rust/allocator/lib.rs
index 29b3af1..a7fa7a4 100644
--- build/rust/allocator/lib.rs
+++ build/rust/allocator/lib.rs
@@ -90,7 +90,14 @@
     #[linkage = "weak"]
     fn __rust_no_alloc_shim_is_unstable_v2() {}
 
+    #[rustc_std_internal_symbol]
+    #[linkage = "weak"]
+    fn __rust_alloc_error_handler_should_panic_v2() -> u8 {
+        0
+    }
+
     // Mangle the symbol name as rustc expects.
+    // TODO(crbug.com/440481922): Remove this after rolling past https://github.com/rust-lang/rust/pull/143387
     #[rustc_std_internal_symbol]
     #[allow(non_upper_case_globals)]
     #[linkage = "weak"]
