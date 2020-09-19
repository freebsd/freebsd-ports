--- cli/ops/tty.rs.orig	2020-09-18 21:28:11 UTC
+++ cli/ops/tty.rs
@@ -311,7 +311,7 @@ fn op_console_size(
         let fd = std_file.as_raw_fd();
         unsafe {
           let mut size: libc::winsize = std::mem::zeroed();
-          if libc::ioctl(fd, libc::TIOCGWINSZ, &mut size as *mut _) != 0 {
+          if libc::ioctl(fd, libc::TIOCGWINSZ.into(), &mut size as *mut _) != 0 {
             return Err(last_os_error());
           }
 
