--- libs/core/uv_compat/tty.rs.orig	2026-07-01 13:28:43 UTC
+++ libs/core/uv_compat/tty.rs
@@ -381,7 +381,7 @@ mod global_termios {
   }
 
   /// Get a pointer to the thread-local errno value.
-  #[cfg(target_os = "macos")]
+  #[cfg(any(target_os = "macos", target_os = "freebsd"))]
   fn errno_location() -> *mut c_int {
     unsafe extern "C" {
       fn __error() -> *mut c_int;
@@ -397,7 +397,7 @@ mod global_termios {
     unsafe { __errno_location() }
   }
 
-  #[cfg(not(any(target_os = "macos", target_os = "linux")))]
+  #[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd")))]
   fn errno_location() -> *mut c_int {
     compile_error!(
       "errno_location not implemented for this platform — \
