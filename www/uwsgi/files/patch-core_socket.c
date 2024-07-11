Fix SOCK_NONBLOCK handling for FreeBSD, copied from NetBSD.
--- core/socket.c.orig	2024-06-05 01:53:18 UTC
+++ core/socket.c
@@ -413,7 +413,7 @@ static int connect_to_unix(char *socket_name, int time
 		memcpy(uws_addr.sun_path, socket_name, UMIN(strlen(socket_name), 102));
 	}
 
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	uwsgi_poll.fd = socket(AF_UNIX, SOCK_STREAM | SOCK_NONBLOCK, 0);
 #else
 	uwsgi_poll.fd = socket(AF_UNIX, SOCK_STREAM, 0);
@@ -453,7 +453,7 @@ static int connect_to_tcp(char *socket_name, int port,
 		uws_addr.sin_addr.s_addr = inet_addr(socket_name);
 	}
 
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	uwsgi_poll.fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
 #else
 	uwsgi_poll.fd = socket(AF_INET, SOCK_STREAM, 0);
@@ -827,7 +827,7 @@ int timed_connect(struct pollfd *fdpoll, const struct 
 	int cnt;
 	/* set non-blocking socket */
 
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	// hmm, nothing to do, as we are already non-blocking
 #else
 	int arg = fcntl(fdpoll->fd, F_GETFL, NULL);
@@ -861,7 +861,7 @@ int timed_connect(struct pollfd *fdpoll, const struct 
 	}
 
 
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	uwsgi_socket_b(fdpoll->fd);
 #else
 	/* re-set blocking socket */
@@ -1907,7 +1907,7 @@ int uwsgi_accept(int server_fd) {
 	struct sockaddr_un client_src;
         memset(&client_src, 0, sizeof(struct sockaddr_un));
         socklen_t client_src_len = 0;
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
         return accept4(server_fd, (struct sockaddr *) &client_src, &client_src_len, SOCK_NONBLOCK);
 #elif defined(__linux__)
         int client_fd = accept(server_fd, (struct sockaddr *) &client_src, &client_src_len);
