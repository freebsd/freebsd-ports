--- cargo-crates/console-0.6.1/src/unix_term.rs.orig	2017-05-11 05:32:00 UTC
+++ cargo-crates/console-0.6.1/src/unix_term.rs
@@ -28,7 +28,7 @@ pub fn terminal_size() -> Option<(u16, u16)> {
         }
 
         let mut winsize: libc::winsize = mem::zeroed();
-        libc::ioctl(libc::STDOUT_FILENO, libc::TIOCGWINSZ, &mut winsize);
+        libc::ioctl(libc::STDOUT_FILENO, libc::TIOCGWINSZ.into(), &mut winsize);
         if winsize.ws_row > 0 && winsize.ws_col > 0 {
             Some((winsize.ws_row as u16, winsize.ws_col as u16))
         } else {
