--- src/conn_sock.c.orig	2026-01-23 16:22:04 UTC
+++ src/conn_sock.c
@@ -360,7 +360,7 @@ void write_back_to_remote_consoles(char *buf, int len)
 	for (int i = local_mainfd_stdin.readers->len; i > 0; i--) {
 		struct remote_sock_s *remote_sock = g_ptr_array_index(local_mainfd_stdin.readers, i - 1);

-		if (remote_sock->writable && write_all(remote_sock->fd, buf, len) < 0) {
+		if (remote_sock->writable && send(remote_sock->fd, buf, len, MSG_EOR) < 0) {
 			nwarn("Failed to write to remote console socket");
 			remote_sock_shutdown(remote_sock, SHUT_WR);
 		}
