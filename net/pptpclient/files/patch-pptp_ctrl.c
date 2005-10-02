--- pptp_ctrl.c.orig	Fri Sep 30 21:56:59 2005
+++ pptp_ctrl.c	Fri Sep 30 21:57:27 2005
@@ -457,6 +457,8 @@
 void pptp_fd_set(PPTP_CONN * conn, fd_set * read_set, fd_set * write_set,
                  int * max_fd)
 {
+    int sig_fd;
+
     assert(conn && conn->call);
     /* Add fd to write_set if there are outstanding writes. */
     if (conn->write_size > 0)
@@ -465,7 +467,7 @@
     FD_SET(conn->inet_sock, read_set);
     if (*max_fd < conn->inet_sock) *max_fd = conn->inet_sock;
     /* Add signal pipe file descriptor to set */
-    int sig_fd = sigpipe_fd();
+    sig_fd = sigpipe_fd();
     FD_SET(sig_fd, read_set);
     if (*max_fd < sig_fd) *max_fd = sig_fd;
 }
