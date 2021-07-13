--- src/ui/image_backends/iterm.rs.orig	2021-07-13 09:56:48 UTC
+++ src/ui/image_backends/iterm.rs
@@ -27,7 +27,7 @@ impl super::ImageBackend for ITermBackend {
     ) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let width_ratio = f64::from(tty_size.ws_col) / f64::from(tty_size.ws_xpixel);
