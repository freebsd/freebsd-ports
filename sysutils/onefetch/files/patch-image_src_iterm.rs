--- image/src/iterm.rs.orig	2022-12-15 04:54:42 UTC
+++ image/src/iterm.rs
@@ -32,7 +32,7 @@ impl super::ImageBackend for ITermBackend {
     ) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let width_ratio = f64::from(tty_size.ws_col) / f64::from(tty_size.ws_xpixel);
