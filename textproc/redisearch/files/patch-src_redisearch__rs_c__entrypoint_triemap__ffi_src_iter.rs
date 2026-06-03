--- src/redisearch_rs/c_entrypoint/triemap_ffi/src/iter.rs.orig	2026-05-30 15:14:56 UTC
+++ src/redisearch_rs/c_entrypoint/triemap_ffi/src/iter.rs
@@ -246,7 +246,9 @@ pub fn timespec_monotonic_now() -> timespec {
     let mut ts = std::mem::MaybeUninit::uninit();
     // SAFETY:
     // We have exclusive access to a pointer of the correct type
-    let ret = unsafe { libc::clock_gettime(libc::CLOCK_MONOTONIC_RAW, ts.as_mut_ptr()) };
+    #[cfg(target_os = "freebsd")] let clock = libc::CLOCK_MONOTONIC;
+    #[cfg(target_os = "linux")] let clock = libc::CLOCK_MONOTONIC_RAW;
+    let ret = unsafe { libc::clock_gettime(clock, ts.as_mut_ptr()) };
     if ret == 0 {
         // SAFETY:
         // `ts` was initialized by before call to `clock_gettime`
