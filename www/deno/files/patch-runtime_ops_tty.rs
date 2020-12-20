--- runtime/ops/tty.rs.orig	2020-12-14 21:25:05 UTC
+++ runtime/ops/tty.rs
@@ -315,7 +315,7 @@ fn op_console_size(
         let fd = std_file.as_raw_fd();
         unsafe {
           let mut size: libc::winsize = std::mem::zeroed();
-          if libc::ioctl(fd, libc::TIOCGWINSZ, &mut size as *mut _) != 0 {
+          if libc::ioctl(fd, libc::TIOCGWINSZ.into(), &mut size as *mut _) != 0 {
             return Err(Error::last_os_error().into());
           }
 
