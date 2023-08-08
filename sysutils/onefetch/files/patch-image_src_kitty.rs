--- image/src/kitty.rs.orig	2022-12-15 04:55:51 UTC
+++ image/src/kitty.rs
@@ -92,7 +92,7 @@ impl super::ImageBackend for KittyBackend {
     ) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let width_ratio = f64::from(tty_size.ws_col) / f64::from(tty_size.ws_xpixel);
