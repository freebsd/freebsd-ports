--- libssh/socket.c.orig	2010-09-06 03:29:26.000000000 +1000
+++ libssh/socket.c	2010-12-05 14:25:26.000000000 +0900
@@ -265,7 +265,10 @@
   if (s->fd == SSH_INVALID_SOCKET)
     return;
   FD_SET(s->fd,set);
-  if (s->fd >= 0 && s->fd != SSH_INVALID_SOCKET) {
+
+  if (s->fd >= 0 &&
+      s->fd >= *max_fd &&
+      s->fd != SSH_INVALID_SOCKET) {
     *max_fd = s->fd + 1;
   }
 }
