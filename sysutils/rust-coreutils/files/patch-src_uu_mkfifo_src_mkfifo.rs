--- src/uu/mkfifo/src/mkfifo.rs.orig	2026-08-06 13:03:23 UTC
+++ src/uu/mkfifo/src/mkfifo.rs
@@ -142,8 +142,12 @@ fn create_fifo(path: &str, mode: u32) -> Result<(), st
 // the umask so the requested mode is applied atomically (see issue #10020).
 #[cfg(not(target_vendor = "apple"))]
 fn create_fifo(path: &str, mode: u32) -> Result<(), std::io::Error> {
-    use rustix::fs::{CWD, mkfifoat};
-    mkfifoat(CWD, path, Mode::from_bits_truncate(mode)).map_err(std::io::Error::from)
+    use rustix::fs;
+    Ok(fs::mkfifoat(
+        fs::CWD,
+        path,
+        Mode::from_bits_truncate(mode as fs::RawMode),
+    )?)
 }
 
 #[cfg(target_vendor = "apple")]
