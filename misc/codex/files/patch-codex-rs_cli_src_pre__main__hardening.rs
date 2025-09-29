--- codex-rs/cli/src/pre_main_hardening.rs.orig	2025-09-26 18:28:59 UTC
+++ codex-rs/cli/src/pre_main_hardening.rs
@@ -4,9 +4,12 @@ const PTRACE_DENY_ATTACH_FAILED_EXIT_CODE: i32 = 6;
 #[cfg(target_os = "macos")]
 const PTRACE_DENY_ATTACH_FAILED_EXIT_CODE: i32 = 6;
 
-#[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "android", target_os = "macos", target_os = "freebsd"))]
 const SET_RLIMIT_CORE_FAILED_EXIT_CODE: i32 = 7;
 
+#[cfg(target_os = "freebsd")]
+const PROCCTL_PROC_TRACE_CTL_FAILED_EXIT_CODE: i32 = 8;
+
 #[cfg(any(target_os = "linux", target_os = "android"))]
 pub(crate) fn pre_main_hardening_linux() {
     // Disable ptrace attach / mark process non-dumpable.
@@ -69,6 +72,43 @@ pub(crate) fn pre_main_hardening_macos() {
         .collect();
 
     for key in dyld_keys {
+        unsafe {
+            std::env::remove_var(key);
+        }
+    }
+}
+
+#[cfg(target_os = "freebsd")]
+pub(crate) fn pre_main_hardening_freebsd() {
+    // Prevent debuggers from attaching to this process
+    let mut arg = libc::PROC_TRACE_CTL_DISABLE_EXEC;
+    let ret_code = unsafe {
+        libc::procctl(libc::P_PID, 0, libc::PROC_TRACE_CTL, &mut arg as *mut _ as *mut libc::c_void)
+    };
+    if ret_code == -1 {
+        eprintln!(
+            "ERROR: procctl(PROC_TRACE_CTL) failed: {}",
+            std::io::Error::last_os_error()
+        );
+        std::process::exit(PROCCTL_PROC_TRACE_CTL_FAILED_EXIT_CODE);
+    }
+
+    // Set the core file size limit to 0 to prevent core dumps.
+    set_core_file_size_limit_to_zero();
+
+    // Remove all LD_ environment variables, which can be used to subvert
+    // library loading.
+    let ld_keys: Vec<String> = std::env::vars()
+        .filter_map(|(key, _)| {
+            if key.starts_with("LD_") {
+                Some(key)
+            } else {
+                None
+            }
+        })
+        .collect();
+
+    for key in ld_keys {
         unsafe {
             std::env::remove_var(key);
         }
