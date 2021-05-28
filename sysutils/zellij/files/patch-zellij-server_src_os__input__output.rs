--- zellij-server/src/os_input_output.rs.orig	2021-05-27 12:15:24 UTC
+++ zellij-server/src/os_input_output.rs
@@ -41,7 +41,7 @@ pub(crate) fn set_terminal_size_using_fd(fd: RawFd, co
         ws_xpixel: 0,
         ws_ypixel: 0,
     };
-    unsafe { ioctl(fd, TIOCSWINSZ, &winsize) };
+    unsafe { ioctl(fd, TIOCSWINSZ.into(), &winsize) };
 }
 
 /// Handle some signals for the child process. This will loop until the child
