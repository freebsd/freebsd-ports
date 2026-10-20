--- src/util/secure_fs/path.rs.orig	2026-10-05 08:27:50 UTC
+++ src/util/secure_fs/path.rs
@@ -41,15 +41,19 @@ impl AnchoredPath {
         Ok(Self { parent, name })
     }
 
-    /// Creates missing parents and opens a chain protected from untrusted renames.
-    pub(crate) fn open_trusted_parent_or_create(path: &Path, mode: u32) -> io::Result<Self> {
+    /// Creates missing parents, trusting root and the explicitly selected runtime UID.
+    pub(crate) fn open_trusted_parent_or_create(
+        path: &Path,
+        mode: u32,
+        trusted_uid: u32,
+    ) -> io::Result<Self> {
         let name = path
             .file_name()
             .filter(|name| !name.is_empty())
             .ok_or_else(|| io::Error::new(io::ErrorKind::InvalidInput, "path has no file name"))?
             .to_os_string();
         let parent_path = path.parent().unwrap_or_else(|| Path::new("."));
-        let parent = open_trusted_dir_nofollow_or_create(parent_path, mode)?;
+        let parent = open_dir_components(parent_path, Some(mode), true, trusted_uid)?;
         Ok(Self { parent, name })
     }
 
@@ -61,7 +65,9 @@ impl AnchoredPath {
     ) -> io::Result<Self> {
         if strict_runtime_paths {
             return match create_mode {
-                Some(mode) => Self::open_trusted_parent_or_create(path, mode),
+                Some(mode) => Self::open_trusted_parent_or_create(
+                    path, mode, nix::unistd::Uid::effective().as_raw(),
+                ),
                 None => Self::open_trusted_parent(path),
             };
         }
@@ -102,11 +108,11 @@ pub(crate) fn open_dir_nofollow(path: &Path) -> io::Re
 
 /// Opens a directory by walking every component with `O_NOFOLLOW`.
 pub(crate) fn open_dir_nofollow(path: &Path) -> io::Result<OwnedFd> {
-    open_dir_components(path, None, false)
+    open_dir_components(path, None, false, 0)
 }
 
 fn open_or_create_dir_nofollow(path: &Path, mode: u32) -> io::Result<OwnedFd> {
-    open_dir_components(path, Some(mode), false)
+    open_dir_components(path, Some(mode), false, 0)
 }
 
 /// Opens a directory after securely creating any missing components.
@@ -116,7 +122,7 @@ pub(crate) fn open_trusted_dir_nofollow_or_create(path
 
 /// Opens or creates a directory chain protected from untrusted entry replacement.
 pub(crate) fn open_trusted_dir_nofollow_or_create(path: &Path, mode: u32) -> io::Result<OwnedFd> {
-    open_dir_components(path, Some(mode), true)
+    open_dir_components(path, Some(mode), true, nix::unistd::Uid::effective().as_raw())
 }
 
 /// Follows parent-directory symlinks without imposing ownership or permission policy.
@@ -136,15 +142,16 @@ pub(crate) fn open_compatible_dir(path: &Path, create_
     open(path, DIRECTORY_FLAGS & !OFlag::O_NOFOLLOW, Mode::empty()).map_err(errno_to_io)
 }
 
-/// Opens a directory only when its entire path is owned by root or the effective user.
+// Opens a directory only when its entire path is owned by root or the effective user.
 fn open_trusted_dir_nofollow(path: &Path) -> io::Result<OwnedFd> {
-    open_dir_components(path, None, true)
+    open_dir_components(path, None, true, nix::unistd::Uid::effective().as_raw())
 }
 
 fn open_dir_components(
     path: &Path,
     create_mode: Option<u32>,
     require_trusted: bool,
+    trusted_uid: u32,
 ) -> io::Result<OwnedFd> {
     let mut names = Vec::new();
     for component in path.components() {
@@ -167,14 +174,14 @@ fn open_dir_components(
     };
     let mut current = open(start, DIRECTORY_FLAGS, Mode::empty()).map_err(errno_to_io)?;
     if require_trusted {
-        validate_trusted_directory(&current, !names.is_empty())?;
+        validate_trusted_directory(&current, !names.is_empty(), trusted_uid)?;
     }
     let component_count = names.len();
     for (index, name) in names.into_iter().enumerate() {
         let next = match openat(&current, name.as_os_str(), DIRECTORY_FLAGS, Mode::empty()) {
             Ok(descriptor) => descriptor,
             Err(nix::errno::Errno::ENOENT) if create_mode.is_some() => {
-                let mode = Mode::from_bits_truncate(create_mode.unwrap_or(0o750));
+                let mode = Mode::from_bits_truncate(create_mode.unwrap_or(0o750) as libc::mode_t);
                 match mkdirat(&current, name.as_os_str(), mode) {
                     Ok(()) | Err(nix::errno::Errno::EEXIST) => {}
                     Err(error) => return Err(errno_to_io(error)),
@@ -185,22 +192,25 @@ fn open_dir_components(
             Err(error) => return Err(errno_to_io(error)),
         };
         if require_trusted {
-            validate_trusted_directory(&next, index + 1 < component_count)?;
+            validate_trusted_directory(&next, index + 1 < component_count, trusted_uid)?;
         }
         current = next;
     }
     Ok(current)
 }
 
-fn validate_trusted_directory(descriptor: &OwnedFd, allow_sticky_parent: bool) -> io::Result<()> {
+fn validate_trusted_directory(
+    descriptor: &OwnedFd,
+    allow_sticky_parent: bool,
+    trusted_uid: u32,
+) -> io::Result<()> {
     let file = std::fs::File::from(descriptor.try_clone()?);
     let metadata = file.metadata()?;
-    let effective_uid = nix::unistd::Uid::effective().as_raw();
     let mode = metadata.permissions().mode();
     let writable_by_others = mode & 0o022 != 0;
     let protected_sticky_parent = allow_sticky_parent && mode & 0o1000 != 0;
     if !metadata.is_dir()
-        || (metadata.uid() != 0 && metadata.uid() != effective_uid)
+        || (metadata.uid() != 0 && metadata.uid() != trusted_uid)
         || (writable_by_others && !protected_sticky_parent)
     {
         return Err(io::Error::new(
