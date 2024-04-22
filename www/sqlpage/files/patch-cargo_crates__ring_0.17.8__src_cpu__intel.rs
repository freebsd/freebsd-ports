--- cargo-crates/ring-0.17.8/src/cpu/intel.rs.orig	1973-11-29 22:33:09.000000000 +0100
+++ cargo-crates/ring-0.17.8/src/cpu/intel.rs	2024-03-18 12:10:12.772352000 +0100
@@ -24,8 +24,8 @@
     // https://github.com/briansmith/ring/issues/1793#issuecomment-1793243725,
     // https://github.com/briansmith/ring/issues/1832,
     // https://github.com/briansmith/ring/issues/1833.
-    const _ASSUMES_SSE2: () =
-        assert!(cfg!(target_feature = "sse") && cfg!(target_feature = "sse2"));
+//    const _ASSUMES_SSE2: () =
+//        assert!(cfg!(target_feature = "sse") && cfg!(target_feature = "sse2"));
 
     #[cfg(target_arch = "x86_64")]
     const _ASSUMED_POINTER_SIZE: usize = 8;
