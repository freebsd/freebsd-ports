--- src/display/cell_size.rs.orig	2020-12-01 03:56:56 UTC
+++ src/display/cell_size.rs
@@ -25,7 +25,7 @@ pub fn cell_size_in_pixels() -> std::io::Result<(u32, 
     };
     let w = winsize { ws_row: 0, ws_col: 0, ws_xpixel: 0, ws_ypixel: 0 };
     let r = unsafe {
-        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)
+        ioctl(STDOUT_FILENO, TIOCGWINSZ.into(), &w)
     };
     if r == 0 && w.ws_xpixel > w.ws_col && w.ws_ypixel > w.ws_row {
         Ok((
