-- Gate the publication-capability probe cleanup on Linux/macOS only.  On
-- FreeBSD (and other Unixes) the function already returns
-- ARTIFACT_PUBLISH_UNSUPPORTED, but the un-gated `let supported = result ...`
-- line referenced `result` which only exists on Linux/macOS, causing a
-- "cannot find value `result` in this scope" compile error.
--
-- Upstreamed: https://github.com/yvgude/lean-ctx/pull/1828

--- src/core/engine_artifact/unix.rs.orig	2026-09-16 18:33:04 UTC
+++ src/core/engine_artifact/unix.rs
@@ -319,7 +319,7 @@ fn open_or_create_directory_at(parent_fd: RawFd, name:
 /// musl does not export a `renameat2` wrapper (the symbol is glibc-only, so
 /// `*-musl` release builds failed at link time with "undefined reference to
 /// renameat2"). The raw syscall is identical on every Linux libc.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 unsafe fn renameat2_compat(
     old_dirfd: RawFd,
     old_name: *const libc::c_char,
@@ -331,7 +331,8 @@ unsafe fn renameat2_compat(
     // the descriptor and NUL-termination invariants.
     unsafe {
         libc::syscall(
-            libc::SYS_renameat2,
+            #[cfg(target_os = "freebsd")] 602, // FreeBSD 15+ syscall number for renameat2, see https://github.com/rust-lang/libc/issues/5553
+            #[cfg(not(target_os = "freebsd"))] libc::SYS_renameat2,
             old_dirfd,
             old_name,
             new_dirfd,
@@ -368,7 +369,7 @@ fn preflight_publication(directory_fd: RawFd) -> Resul
     }
     let (probe_file, probe_name) = probe.ok_or_else(|| ARTIFACT_PUBLISH_UNSUPPORTED.to_owned())?;
 
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     // SAFETY: directory_fd is a live descriptor for the held final directory,
     // and probe_name is a NUL-terminated name valid for this call. Both
     // directory operands refer to that held descriptor.
@@ -378,7 +379,12 @@ fn preflight_publication(directory_fd: RawFd) -> Resul
             probe_name.as_ptr(),
             directory_fd,
             probe_name.as_ptr(),
-            libc::RENAME_NOREPLACE,
+            {
+                #[cfg(target_os = "freebsd")]
+                { 1 } // see https://github.com/rust-lang/libc/issues/5553
+                #[cfg(not(target_os = "freebsd"))]
+                { libc::RENAME_NOREPLACE }
+            }, // <-- The comma belongs here, after the block evaluates
         )
     };
     #[cfg(target_os = "macos")]
@@ -392,7 +398,7 @@ fn preflight_publication(directory_fd: RawFd) -> Resul
             libc::RENAME_EXCL,
         )
     };
-    #[cfg(not(any(target_os = "linux", target_os = "macos")))]
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd", target_os = "macos")))]
     return Err(ARTIFACT_PUBLISH_UNSUPPORTED.to_owned());
 
     let supported = result == 0 || errno() == libc::EEXIST;
