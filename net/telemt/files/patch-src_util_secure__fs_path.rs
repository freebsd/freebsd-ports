--- src/util/secure_fs/path.rs.orig	2026-09-28 20:30:20 UTC
+++ src/util/secure_fs/path.rs
@@ -97,7 +97,7 @@ pub(crate) fn open_trusted_dir_nofollow_or_create(path
     open_dir_components(path, Some(mode), true)
 }
 
-/// Opens a directory only when its entire path is owned by root or the effective user.
+// Opens a directory only when its entire path is owned by root or the effective user.
 fn open_trusted_dir_nofollow(path: &Path) -> io::Result<OwnedFd> {
     open_dir_components(path, None, true)
 }
@@ -135,7 +135,7 @@ fn open_dir_components(
         let next = match openat(&current, name.as_os_str(), DIRECTORY_FLAGS, Mode::empty()) {
             Ok(descriptor) => descriptor,
             Err(nix::errno::Errno::ENOENT) if create_mode.is_some() => {
-                let mode = Mode::from_bits_truncate(create_mode.unwrap_or(0o750));
+                let mode = Mode::from_bits_truncate(create_mode.unwrap_or(0o750) as libc::mode_t);
                 match mkdirat(&current, name.as_os_str(), mode) {
                     Ok(()) | Err(nix::errno::Errno::EEXIST) => {}
                     Err(error) => return Err(errno_to_io(error)),
