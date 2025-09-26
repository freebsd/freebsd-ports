--- ext/os/lib.rs.orig	2023-01-13 13:12:37 UTC
+++ ext/os/lib.rs
@@ -4,6 +4,7 @@ use std::env;
 use std::collections::HashMap;
 use std::collections::HashSet;
 use std::env;
+use std::path::PathBuf;
 use std::sync::Arc;
 use std::sync::atomic::AtomicI32;
 use std::sync::atomic::Ordering;
@@ -112,7 +113,8 @@ fn op_exec_path() -> Result<String, OsError> {
 #[op2]
 #[string]
 fn op_exec_path() -> Result<String, OsError> {
-  let current_exe = env::current_exe().unwrap();
+  let current_exe =
+    env::current_exe().unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno"));
   // normalize path so it doesn't include '.' or '..' components
   let path = normalize_path(Cow::Owned(current_exe));
 
@@ -660,6 +662,46 @@ fn rss() -> u64 {
   } else {
     0
   }
+}
+
+#[cfg(target_os = "freebsd")]
+fn rss() -> usize {
+  // Uses FreeBSD's KERN_PROC_PID sysctl(2)
+  // to retrieve information about the current
+  // process, part of which is the RSS (ki_rssize)
+  let pid = unsafe { libc::getpid() };
+  // SAFETY: libc call (get system page size)
+  let pagesize = unsafe { libc::sysconf(libc::_SC_PAGESIZE) } as usize;
+  // KERN_PROC_PID returns a struct libc::kinfo_proc
+  let mut kinfoproc = std::mem::MaybeUninit::<libc::kinfo_proc>::uninit();
+  let mut size = std::mem::size_of_val(&kinfoproc) as libc::size_t;
+  let mut mib = [
+    libc::CTL_KERN,
+    libc::KERN_PROC,
+    libc::KERN_PROC_PID,
+    pid,
+  ];
+  // SAFETY: libc call, mib has been statically initialized,
+  // kinfoproc is a valid pointer to a libc::kinfo_proc struct
+  let res = unsafe {
+    libc::sysctl(
+      mib.as_mut_ptr(),
+      mib.len() as _,
+      kinfoproc.as_mut_ptr() as *mut libc::c_void,
+      &mut size,
+      std::ptr::null_mut(),
+      0,
+    )
+  };
+
+  if res == 0 {
+    // SAFETY: sysctl returns 0 on success and kinfoproc is initialized
+    // ki_rssize contains size in pages -> multiply with pagesize to
+    // get size in bytes.
+    pagesize * unsafe { (*kinfoproc.as_mut_ptr()).ki_rssize as usize }
+  } else {
+  0
+  } 
 }
 
 #[cfg(windows)]
