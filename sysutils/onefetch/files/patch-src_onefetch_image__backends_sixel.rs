--- src/onefetch/image_backends/sixel.rs.orig	2020-12-09 14:22:47 UTC
+++ src/onefetch/image_backends/sixel.rs
@@ -74,7 +74,7 @@ impl super::ImageBackend for SixelBackend {
     fn add_image(&self, lines: Vec<String>, image: &DynamicImage, colors: usize) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let cw = tty_size.ws_xpixel / tty_size.ws_col;
