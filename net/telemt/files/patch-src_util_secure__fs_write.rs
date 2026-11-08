--- src/util/secure_fs/write.rs.orig	2026-09-28 20:30:20 UTC
+++ src/util/secure_fs/write.rs
@@ -14,7 +14,7 @@ fn open_regular_at(anchored: &AnchoredPath, flags: OFl
         anchored.parent(),
         anchored.name(),
         flags | OFlag::O_NOFOLLOW | OFlag::O_CLOEXEC,
-        Mode::from_bits_truncate(mode),
+        Mode::from_bits_truncate(mode as libc::mode_t),
     )
     .map_err(errno_to_io)?;
     let file = std::fs::File::from(descriptor);
@@ -41,7 +41,7 @@ pub(crate) fn read_regular_limited(path: &Path, max_by
     let mut file = open_regular_at(
         &anchored,
         OFlag::O_RDONLY | OFlag::O_NONBLOCK,
-        Mode::empty().bits(),
+        Mode::empty().bits().into(),
     )?;
     let before = file.metadata()?;
     if before.len() > max_bytes as u64 {
@@ -116,7 +116,7 @@ pub(crate) fn open_append_regular_at<Fd: AsFd>(
         parent,
         name,
         OFlag::O_WRONLY | OFlag::O_APPEND | OFlag::O_CREAT | OFlag::O_NOFOLLOW | OFlag::O_CLOEXEC,
-        Mode::from_bits_truncate(mode),
+        Mode::from_bits_truncate(mode as libc::mode_t),
     )
     .map_err(errno_to_io)?;
     let file = std::fs::File::from(descriptor);
@@ -160,7 +160,7 @@ fn atomic_replace_anchored(anchored: &AnchoredPath, co
         anchored.parent(),
         temp_name.as_str(),
         OFlag::O_WRONLY | OFlag::O_CREAT | OFlag::O_EXCL | OFlag::O_NOFOLLOW | OFlag::O_CLOEXEC,
-        Mode::from_bits_truncate(mode),
+        Mode::from_bits_truncate(mode as libc::mode_t),
     )
     .map_err(errno_to_io)?;
     let result = write_and_publish(descriptor, anchored, &temp_name, contents);
@@ -193,6 +193,7 @@ fn write_and_publish(
     fsync(anchored.parent()).map_err(errno_to_io)
 }
 
+/// Exercises publication through a previously anchored parent directory.
 #[cfg(test)]
 pub(super) fn atomic_replace_after_anchor(
     anchored: &AnchoredPath,
