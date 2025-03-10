--- cargo-crates/ring-0.17.9/src/cpu/intel.rs.orig	2025-02-18 22:59:16.393822000 +0100
+++ cargo-crates/ring-0.17.11/src/cpu/intel.rs	2025-02-18 22:59:40.189467000 +0100
@@ -156,8 +156,6 @@
     // CMOV, it is likely that some of our timing side channel prevention does
     // not work. Presumably the people who delete these are verifying that it
     // all works fine.
-    const _SSE_REQUIRED: () = assert!(cfg!(target_feature = "sse"));
-    const _SSE2_REQUIRED: () = assert!(cfg!(target_feature = "sse2"));
 
     #[cfg(all(target_arch = "x86", not(target_feature = "sse2")))]
     {
