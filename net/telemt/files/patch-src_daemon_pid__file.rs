--- src/daemon/pid_file.rs.orig	2026-09-28 20:30:20 UTC
+++ src/daemon/pid_file.rs
@@ -240,7 +240,7 @@ fn open_file_at(anchor: &AnchoredPath, name: &OsStr, f
 }
 
 fn open_file_at(anchor: &AnchoredPath, name: &OsStr, flags: OFlag, mode: u32) -> io::Result<File> {
-    let descriptor = openat(anchor.parent(), name, flags, Mode::from_bits_truncate(mode))
+    let descriptor = openat(anchor.parent(), name, flags, Mode::from_bits_truncate(mode as libc::mode_t))
         .map_err(|error| io::Error::from_raw_os_error(error as i32))?;
     Ok(File::from(descriptor))
 }
