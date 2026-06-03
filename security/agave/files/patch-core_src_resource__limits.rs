--- core/src/resource_limits.rs.orig	2026-04-14 19:53:57 UTC
+++ core/src/resource_limits.rs
@@ -45,8 +45,8 @@ pub fn adjust_nofile_limit(enforce_nofile_limit: bool)
         let return_value = unsafe { libc::setrlimit(libc::RLIMIT_NOFILE, &nofile) };
         if return_value != 0 {
             let error = ResourceLimitError::Nofile {
-                desired: desired_nofile,
-                current,
+                desired: desired_nofile as u64,
+                current: current as u64,
                 error: return_value,
             };
 
