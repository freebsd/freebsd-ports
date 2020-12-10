--- src/onefetch/image_backends/kitty.rs.orig	2020-12-09 14:30:15 UTC
+++ src/onefetch/image_backends/kitty.rs
@@ -77,7 +77,7 @@ impl super::ImageBackend for KittyBackend {
     ) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let width_ratio = f64::from(tty_size.ws_col) / f64::from(tty_size.ws_xpixel);
