--- runtime/ops/tty.rs.orig	2026-07-01 13:28:43 UTC
+++ runtime/ops/tty.rs
@@ -424,7 +424,7 @@ fn console_size_from_fd(
   // SAFETY: libc calls
   unsafe {
     let mut size: libc::winsize = std::mem::zeroed();
-    if libc::ioctl(fd, libc::TIOCGWINSZ, &mut size as *mut _) != 0 {
+    if libc::ioctl(fd, libc::TIOCGWINSZ.into(), &mut size as *mut _) != 0 {
       return Err(Error::last_os_error());
     }
     Ok(ConsoleSize {
