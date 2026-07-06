--- ext/node/ops/os/priority.rs.orig	2026-07-01 13:28:43 UTC
+++ ext/node/ops/os/priority.rs
@@ -26,7 +26,7 @@ mod impl_ {
     set_errno(Errno(0));
     match (
       // SAFETY: libc::getpriority is unsafe
-      unsafe { libc::getpriority(PRIO_PROCESS, pid as id_t) },
+      unsafe { libc::getpriority(PRIO_PROCESS, (pid as id_t).try_into().unwrap()) },
       errno(),
     ) {
       (-1, Errno(0)) => Ok(-1),
@@ -40,7 +40,7 @@ mod impl_ {
     priority: i32,
   ) -> Result<(), super::PriorityError> {
     // SAFETY: libc::setpriority is unsafe
-    match unsafe { libc::setpriority(PRIO_PROCESS, pid as id_t, priority) } {
+    match unsafe { libc::setpriority(PRIO_PROCESS, (pid as id_t).try_into().unwrap(), priority) } {
       -1 => Err(std::io::Error::last_os_error().into()),
       _ => Ok(()),
     }
