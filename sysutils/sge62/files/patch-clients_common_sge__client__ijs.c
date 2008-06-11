
$FreeBSD$

--- clients/common/sge_client_ijs.c.orig
+++ clients/common/sge_client_ijs.c
@@ -36,7 +36,7 @@
 #include <signal.h>
 #include <string.h>
 
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(FREEBSD)
 #  include <termios.h>
 #  include <sys/ttycom.h>
 #  include <sys/ioctl.h>
@@ -192,19 +192,19 @@
     *  indication until the terminal is closed."
     */
    if (signal(SIGHUP, SIG_IGN) != SIG_IGN) {
-      sigset(SIGHUP, signal_handler);
+      signal(SIGHUP, signal_handler);
    }
    if (signal(SIGINT, SIG_IGN) != SIG_IGN) {
-      sigset(SIGINT, signal_handler);
+      signal(SIGINT, signal_handler);
    }
    if (signal(SIGQUIT, SIG_IGN) != SIG_IGN) {
-      sigset(SIGQUIT, signal_handler);
+      signal(SIGQUIT, signal_handler);
    }
    if (signal(SIGTERM, SIG_IGN) != SIG_IGN) {
-      sigset(SIGTERM, signal_handler);
+      signal(SIGTERM, signal_handler);
    }
-   sigset(SIGWINCH, window_change_handler);
-   sigset(SIGPIPE,  broken_pipe_handler);
+   signal(SIGWINCH, window_change_handler);
+   signal(SIGPIPE,  broken_pipe_handler);
 }
 
 /****** client_check_window_change() *******************************************
