--- ext/node/ops/os/priority.rs.orig	2023-08-21 14:55:59 UTC
+++ ext/node/ops/os/priority.rs
@@ -68,7 +68,7 @@ mod priority {
     set_errno(Errno(0));
     match (
       // SAFETY: libc::getpriority is unsafe
-      unsafe { libc::getpriority(PRIO_PROCESS, pid as id_t) },
+      unsafe { libc::getpriority(PRIO_PROCESS, (pid as id_t).try_into().unwrap()) },
       errno(),
     ) {
       (-1, Errno(0)) => Ok(PRIORITY_HIGH),
@@ -79,7 +79,7 @@ mod priority {
 
   pub fn set_priority(pid: u32, priority: i32) -> Result<(), AnyError> {
     // SAFETY: libc::setpriority is unsafe
-    match unsafe { libc::setpriority(PRIO_PROCESS, pid as id_t, priority) } {
+    match unsafe { libc::setpriority(PRIO_PROCESS, (pid as id_t).try_into().unwrap(), priority) } {
       -1 => Err(std::io::Error::last_os_error().into()),
       _ => Ok(()),
     }
