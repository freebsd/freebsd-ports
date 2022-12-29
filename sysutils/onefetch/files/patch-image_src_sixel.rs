--- image/src/sixel.rs.orig	2022-12-15 04:56:28 UTC
+++ image/src/sixel.rs
@@ -82,7 +82,7 @@ impl super::ImageBackend for SixelBackend {
     fn add_image(&self, lines: Vec<String>, image: &DynamicImage, colors: usize) -> Result<String> {
         let tty_size = unsafe {
             let tty_size: winsize = std::mem::zeroed();
-            ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty_size);
+            ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &tty_size);
             tty_size
         };
         let cw = tty_size.ws_xpixel / tty_size.ws_col;
