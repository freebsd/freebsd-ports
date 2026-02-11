--- cargo-crates/libc-0.2.175/src/unix/bsd/freebsdlike/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libc-0.2.175/src/unix/bsd/freebsdlike/mod.rs
@@ -1,7 +1,7 @@ use crate::prelude::*;
 use crate::off_t;
 use crate::prelude::*;
 
-pub type mode_t = u16;
+pub type mode_t = u32;
 pub type pthread_attr_t = *mut c_void;
 pub type rlim_t = i64;
 pub type pthread_mutex_t = *mut c_void;
