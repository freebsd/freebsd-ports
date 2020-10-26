--- cargo-crates/rlimit-0.4.0/src/lib.rs.orig	2020-08-11 04:32:32 UTC
+++ cargo-crates/rlimit-0.4.0/src/lib.rs
@@ -87,7 +87,7 @@ pub type RawResource = __resource_t;
 pub enum Resource {
     /// The maximum size (in bytes)
     /// of the process's virtual memory (address space).
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios", target_os = "freebsd"))]
     AS = libc::RLIMIT_AS as _,
 
     /// The maximum size (in bytes)
@@ -115,7 +115,7 @@ pub enum Resource {
 
     /// The maximum number (in bytes)
     /// of memory that may be locked into RAM.
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios", target_os = "freebsd"))]
     MEMLOCK = libc::RLIMIT_MEMLOCK as _,
 
     /// A limit on the number
@@ -133,12 +133,12 @@ pub enum Resource {
     /// This specifies a value
     /// one greater than the maximum file descriptor number
     /// that can be opened by this process.
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios", target_os = "freebsd"))]
     NOFILE = libc::RLIMIT_NOFILE as _,
 
     /// A limit on the number of extant process (or, more precisely on Linux, threads)
     /// for the real user ID of the calling process.
-    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "ios", target_os = "freebsd"))]
     NPROC = libc::RLIMIT_NPROC as _,
 
     /// A limit (in bytes)
