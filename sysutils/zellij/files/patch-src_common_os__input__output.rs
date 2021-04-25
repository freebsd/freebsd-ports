--- src/common/os_input_output.rs.orig	2021-04-23 08:43:45 UTC
+++ src/common/os_input_output.rs
@@ -45,7 +45,7 @@ pub fn get_terminal_size_using_fd(fd: RawFd) -> Positi
         ws_ypixel: 0,
     };
 
-    unsafe { ioctl(fd, TIOCGWINSZ, &mut winsize) };
+    unsafe { ioctl(fd, TIOCGWINSZ.into(), &mut winsize) };
     PositionAndSize::from(winsize)
 }
 
@@ -60,7 +60,7 @@ pub fn set_terminal_size_using_fd(fd: RawFd, columns: 
         ws_xpixel: 0,
         ws_ypixel: 0,
     };
-    unsafe { ioctl(fd, TIOCSWINSZ, &winsize) };
+    unsafe { ioctl(fd, TIOCSWINSZ.into(), &winsize) };
 }
 
 /// Handle some signals for the child process. This will loop until the child
