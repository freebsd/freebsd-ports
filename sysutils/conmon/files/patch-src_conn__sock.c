--- src/conn_sock.c.orig	2023-07-07 12:04:59 UTC
+++ src/conn_sock.c
@@ -110,6 +110,14 @@ static void bind_relative_to_dir(int dir_fd, int sock_
 	if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
 		pexit("Failed to bind to console-socket");
 }
+
+static void set_socket_buffers(G_GNUC_UNUSED int fd)
+{
+	/*
+	 * Nothing needed here for Linux - the default buffer sizes for unix domain sockets are large enough.
+	 */
+}
+
 #endif
 
 #ifdef __FreeBSD__
@@ -135,6 +143,18 @@ static void bind_relative_to_dir(int dir_fd, int sock_
 	if (fchmodat(dir_fd, addr.sun_path, 0700, AT_SYMLINK_NOFOLLOW))
 		pexit("Failed to change console-socket permissions");
 }
+
+static void set_socket_buffers(int fd)
+{
+	int sz = CONN_SOCK_BUF_SIZE;
+	if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, &sz, sizeof(sz))) {
+		nwarn("failed to set socket receive buffer size");
+	}
+	if (setsockopt(fd, SOL_SOCKET, SO_SNDBUF, &sz, sizeof(sz))) {
+		nwarn("failed to set socket send buffer size");
+	}
+}
+
 #endif
 
 static char *setup_socket(int *fd, const char *path)
@@ -357,6 +377,7 @@ static gboolean attach_cb(int fd, G_GNUC_UNUSED GIOCon
 			nwarn("Failed to accept client connection on attach socket");
 	} else {
 		struct remote_sock_s *remote_sock;
+		set_socket_buffers(new_fd);
 		if (srcsock->dest->readers == NULL) {
 			srcsock->dest->readers = g_ptr_array_new_with_free_func(free);
 		}
