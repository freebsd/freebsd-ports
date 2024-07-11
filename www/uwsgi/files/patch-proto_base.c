Fix SOCK_NONBLOCK handling for FreeBSD, copied from NetBSD.
--- proto/base.c.orig	2024-06-05 02:00:36 UTC
+++ proto/base.c
@@ -97,7 +97,7 @@ int uwsgi_proto_base_accept(struct wsgi_request *wsgi_
 int uwsgi_proto_base_accept(struct wsgi_request *wsgi_req, int fd) {
 
 	wsgi_req->c_len = sizeof(struct sockaddr_un);
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) ||defined(__FreeBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	return accept4(fd, (struct sockaddr *) &wsgi_req->client_addr, (socklen_t *) & wsgi_req->c_len, SOCK_NONBLOCK);
 #elif defined(__linux__)
 	int client_fd = accept(fd, (struct sockaddr *) &wsgi_req->client_addr, (socklen_t *) & wsgi_req->c_len);
