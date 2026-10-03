Implement process.title on FreeBSD with setproctitle(3).

--- ext/node/ops/process.rs.orig	2026-10-02 17:58:05 UTC
+++ ext/node/ops/process.rs
@@ -187,9 +187,21 @@ fn set_process_title(title: &str) {
   }
 }
 
+#[cfg(target_os = "freebsd")]
+fn set_process_title(title: &str) {
+  if let Ok(c_title) = std::ffi::CString::new(title) {
+    // SAFETY: both arguments are valid null-terminated C strings. The leading
+    // '-' in the format skips the default "progname: " prefix.
+    unsafe {
+      libc::setproctitle(c"-%s".as_ptr(), c_title.as_ptr());
+    }
+  }
+}
+
 #[cfg(not(any(
   target_os = "macos",
   target_os = "linux",
+  target_os = "freebsd",
   target_os = "windows"
 )))]
 fn set_process_title(_title: &str) {
