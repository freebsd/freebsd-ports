--- cli/ops/tty.rs.orig	2020-08-31 16:42:11 UTC
+++ cli/ops/tty.rs
@@ -309,7 +309,7 @@ fn op_console_size(
         let fd = std_file.as_raw_fd();
         unsafe {
           let mut size: libc::winsize = std::mem::zeroed();
-          if libc::ioctl(fd, libc::TIOCGWINSZ, &mut size as *mut _) != 0 {
+          if libc::ioctl(fd, libc::TIOCGWINSZ.into(), &mut size as *mut _) != 0 {
             return Err(ErrBox::last_os_error());
           }
 
