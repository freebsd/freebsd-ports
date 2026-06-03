--- libs/core/uv_compat/tty.rs.orig	2026-03-27 11:37:23.000000000 +0100
+++ libs/core/uv_compat/tty.rs	2026-03-31 09:06:58.300848000 +0200
@@ -378,7 +378,7 @@ mod global_termios {
   }
 
   /// Get a pointer to the thread-local errno value.
-  #[cfg(target_os = "macos")]
+  #[cfg(any(target_os = "macos", target_os = "freebsd"))]
   fn errno_location() -> *mut c_int {
     unsafe extern "C" {
       fn __error() -> *mut c_int;
@@ -394,7 +394,7 @@ mod global_termios {
     unsafe { __errno_location() }
   }
 
-  #[cfg(not(any(target_os = "macos", target_os = "linux")))]
+  #[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd")))]
   fn errno_location() -> *mut c_int {
     compile_error!(
       "errno_location not implemented for this platform — \
