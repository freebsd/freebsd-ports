--- src/path.rs.orig	2025-09-15 19:16:57 UTC
+++ src/path.rs
@@ -710,7 +710,7 @@ fn path_remoteness(path: &wstr) -> DirRemoteness {
     #[cfg(not(target_os = "linux"))]
     {
         fn remoteness_via_statfs<StatFS, Flags>(
-            statfn: unsafe extern "C" fn(*const i8, *mut StatFS) -> libc::c_int,
+            statfn: unsafe extern "C" fn(*const libc::c_char, *mut StatFS) -> libc::c_int,
             flagsfn: fn(&StatFS) -> Flags,
             is_local_flag: u64,
             path: &std::ffi::CStr,
