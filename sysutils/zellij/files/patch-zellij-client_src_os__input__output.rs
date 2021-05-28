--- zellij-client/src/os_input_output.rs.orig	2021-05-27 12:15:24 UTC
+++ zellij-client/src/os_input_output.rs
@@ -45,7 +45,7 @@ pub(crate) fn get_terminal_size_using_fd(fd: RawFd) ->
         ws_ypixel: 0,
     };
 
-    unsafe { ioctl(fd, TIOCGWINSZ, &mut winsize) };
+    unsafe { ioctl(fd, TIOCGWINSZ.into(), &mut winsize) };
     PositionAndSize::from(winsize)
 }
 
