--- src/display/cell_size.rs.orig	2020-12-20 12:52:58 UTC
+++ src/display/cell_size.rs
@@ -29,7 +29,7 @@ pub fn cell_size_in_pixels() -> std::io::Result<(u32, 
         ws_xpixel: 0,
         ws_ypixel: 0,
     };
-    let r = unsafe { ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) };
+    let r = unsafe { ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &w) };
     if r == 0 && w.ws_xpixel > w.ws_col && w.ws_ypixel > w.ws_row {
         Ok((
             (w.ws_xpixel / w.ws_col) as u32,
