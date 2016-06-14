--- ipc.c.orig	2016-02-17 21:02:06 UTC
+++ ipc.c
@@ -50,9 +50,22 @@ int ipc_server_init(void)
 	if (server_sd >= 0)
 		close(server_sd);
 
+#ifdef SOCK_CLOEXEC
 	server_sd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
+#else
+	server_sd = socket(AF_UNIX, SOCK_STREAM, 0);
+#endif
 	if (server_sd < 0)
 		return -1;
+#ifndef SOCK_CLOEXEC
+	if (fcntl(server_sd, F_SETFD, FD_CLOEXEC) < 0) {
+		int err = errno;
+		close(server_sd);
+		server_sd = -1;
+		errno = err;
+		return server_sd;
+	}
+#endif
 
 #ifdef HAVE_SOCKADDR_UN_SUN_LEN
 	sa.sun_len = 0;	/* <- correct length is set by the OS */
@@ -89,10 +102,26 @@ int ipc_client_init(void)
 	if (client_sd >= 0)
 		close(client_sd);
 
+#ifdef SOCK_CLOEXEC
 	client_sd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
+#else
+	client_sd = socket(AF_UNIX, SOCK_STREAM, 0);
+#endif
 	if (client_sd < 0)
 		return -1;
 
+#ifndef SOCK_CLOEXEC
+	if (fcntl(client_sd, F_SETFD, FD_CLOEXEC) < 0) {
+		int err = errno;
+
+		close(client_sd);
+		client_sd = -1;
+
+		errno = err;
+		return -1;
+	}
+#endif
+
 #ifdef HAVE_SOCKADDR_UN_SUN_LEN
 	sa.sun_len = 0;	/* <- correct length is set by the OS */
 #endif
