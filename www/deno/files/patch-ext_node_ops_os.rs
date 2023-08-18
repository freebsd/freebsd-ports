--- ext/node/ops/os.rs.orig	2023-08-21 14:55:59 UTC
+++ ext/node/ops/os.rs
@@ -66,6 +66,9 @@ mod priority {
   #[cfg(target_os = "linux")]
   #[allow(non_camel_case_types)]
   type priority_t = u32;
+  #[cfg(target_os = "freebsd")]
+  #[allow(non_camel_case_types)]
+  type priority_t = i32;
 
   const PRIORITY_HIGH: i32 = -14;
 
@@ -74,7 +77,7 @@ mod priority {
     set_errno(Errno(0));
     match (
       // SAFETY: libc::getpriority is unsafe
-      unsafe { libc::getpriority(PRIO_PROCESS as priority_t, pid as id_t) },
+      unsafe { libc::getpriority(PRIO_PROCESS as priority_t, (pid as id_t).try_into().unwrap()) },
       errno(),
     ) {
       (-1, Errno(0)) => Ok(PRIORITY_HIGH),
@@ -86,7 +89,7 @@ mod priority {
   pub fn set_priority(pid: u32, priority: i32) -> Result<(), AnyError> {
     // SAFETY: libc::setpriority is unsafe
     match unsafe {
-      libc::setpriority(PRIO_PROCESS as priority_t, pid as id_t, priority)
+      libc::setpriority(PRIO_PROCESS as priority_t, (pid as id_t).try_into().unwrap(), priority)
     } {
       -1 => Err(std::io::Error::last_os_error().into()),
       _ => Ok(()),
