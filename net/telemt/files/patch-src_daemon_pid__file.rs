--- src/daemon/pid_file.rs.orig	2026-10-05 08:27:50 UTC
+++ src/daemon/pid_file.rs
@@ -68,15 +68,34 @@ impl PidFile {
     ///
     /// Fails if another owner holds the lock or the existing PID names a running process.
     pub fn acquire(&mut self) -> Result<(), DaemonError> {
-        let anchor =
-            AnchoredPath::open_runtime_parent(&self.path, Some(0o755), self.strict_runtime_paths)
-                .map_err(|error| {
-                DaemonError::PidFile(format!(
-                    "cannot open PID parent for {}: {}",
-                    self.path.display(),
-                    error
-                ))
-            })?;
+        self.acquire_for_user(None)
+    }
+
+    /// Acquires the PID lock while trusting root and the selected runtime user
+    /// throughout the parent directory chain, before privileges are dropped.
+    /// Only root may select a runtime UID different from the effective UID.
+    pub(crate) fn acquire_for_user(&mut self, user: Option<&str>) -> Result<(), DaemonError> {
+        let effective_uid = nix::unistd::Uid::effective();
+        let trusted_uid = match user {
+            Some(user) => super::lookup_user(user)?,
+            None => effective_uid,
+        };
+        // Reject unauthorized identity changes before trusting paths or creating files.
+        if !effective_uid.is_root() && trusted_uid != effective_uid {
+            return Err(DaemonError::PrivilegeDrop(nix::errno::Errno::EPERM));
+        }
+        let anchor = if self.strict_runtime_paths {
+            AnchoredPath::open_trusted_parent_or_create(&self.path, 0o755, trusted_uid.as_raw())
+        } else {
+            AnchoredPath::open_runtime_parent(&self.path, Some(0o755), false)
+        }
+        .map_err(|error| {
+            DaemonError::PidFile(format!(
+                "cannot open PID parent for {}: {}",
+                self.path.display(),
+                error
+            ))
+        })?;
         let lock_name = self.lock_path.file_name().ok_or_else(|| {
             DaemonError::PidFile(format!(
                 "lock path {} has no file name",
@@ -243,7 +262,7 @@ fn open_file_at(anchor: &AnchoredPath, name: &OsStr, f
 }
 
 fn open_file_at(anchor: &AnchoredPath, name: &OsStr, flags: OFlag, mode: u32) -> io::Result<File> {
-    let descriptor = openat(anchor.parent(), name, flags, Mode::from_bits_truncate(mode))
+    let descriptor = openat(anchor.parent(), name, flags, Mode::from_bits_truncate(mode as libc::mode_t))
         .map_err(|error| io::Error::from_raw_os_error(error as i32))?;
     Ok(File::from(descriptor))
 }
