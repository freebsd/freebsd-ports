Fix build on FreeBSD 10.3/i386

error[E0308]: mismatched types                                                                                       
  --> cargo-crates/datetime-0.4.5/src/system.rs:76:6                                                                 
   |                                                                                                                 
76 |     (tv.tv_sec, (tv.tv_nsec / 1000) as i16)                                                                     
   |      ^^^^^^^^^ expected i64, found i32                                                                          

--- cargo-crates/datetime-0.4.5/src/system.rs.orig	2017-10-01 10:07:40 UTC
+++ cargo-crates/datetime-0.4.5/src/system.rs
@@ -73,7 +73,7 @@ fn file_time_as_u64(ft: &FILETIME) -> u64 {
 pub unsafe fn sys_time() -> (i64, i16) {
     let mut tv = libc::timespec { tv_sec: 0, tv_nsec: 0 };
     let _ = clock_gettime(libc::CLOCK_REALTIME, &mut tv);
-    (tv.tv_sec, (tv.tv_nsec / 1000) as i16)
+    (tv.tv_sec as i64, (tv.tv_nsec / 1000) as i16)
 }
 
 /// Returns the system’s current time, as a tuple of seconds elapsed since
