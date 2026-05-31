--- src/redisearch_rs/c_entrypoint/iterators_ffi/src/timespec.rs.orig	2026-05-30 15:20:39 UTC
+++ src/redisearch_rs/c_entrypoint/iterators_ffi/src/timespec.rs
@@ -65,7 +65,9 @@ fn monotonic_now_timespec() -> ffi::timespec {
 
     // SAFETY: `&mut ts` is a valid, properly aligned, writable pointer to
     // `libc::timespec`, and `CLOCK_MONOTONIC_RAW` is a valid clock id.
-    let rc = unsafe { libc::clock_gettime(libc::CLOCK_MONOTONIC_RAW, &mut ts) };
+    #[cfg(target_os = "freebsd")] let clock = libc::CLOCK_MONOTONIC;
+    #[cfg(target_os = "linux")] let clock = libc::CLOCK_MONOTONIC_RAW;
+    let rc = unsafe { libc::clock_gettime(clock, &mut ts) };
     debug_assert_eq!(rc, 0);
 
     ffi::timespec {
