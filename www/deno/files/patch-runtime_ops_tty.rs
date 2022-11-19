--- runtime/ops/tty.rs.orig	2020-12-14 21:25:05 UTC
+++ runtime/ops/tty.rs
@@ -232,7 +232,7 @@ fn op_console_size(
         #[allow(clippy::undocumented_unsafe_blocks)]
         unsafe {
           let mut size: libc::winsize = std::mem::zeroed();
-          if libc::ioctl(fd, libc::TIOCGWINSZ, &mut size as *mut _) != 0 {
+          if libc::ioctl(fd, libc::TIOCGWINSZ.into(), &mut size as *mut _) != 0 {
             return Err(Error::last_os_error().into());
           }
           result[0] = size.ws_col as u32;
