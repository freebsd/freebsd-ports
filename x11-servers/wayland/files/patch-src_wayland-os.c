--- src/wayland-os.c.orig	2015-07-06 19:38:51 UTC
+++ src/wayland-os.c
@@ -25,14 +25,20 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#endif
+#ifdef HAVE_SYS_EVENT_H
+#include <sys/event.h>
+#endif
 
-#include "../config.h"
 #include "wayland-os.h"
 
 static int
@@ -62,26 +68,50 @@ wl_os_socket_cloexec(int domain, int typ
 {
 	int fd;
 
+#ifdef SOCK_CLOEXEC
 	fd = socket(domain, type | SOCK_CLOEXEC, protocol);
 	if (fd >= 0)
 		return fd;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	fd = socket(domain, type, protocol);
 	return set_cloexec_or_close(fd);
 }
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2])
+{
+       int retval;
+
+#ifdef SOCK_CLOEXEC
+       retval = socketpair(domain, type | SOCK_CLOEXEC, protocol, sv);
+       if (retval >= 0)
+               return retval;
+       if (errno != EINVAL)
+               return -1;
+#endif
+
+       retval = socketpair(domain, type, protocol, sv);
+       if (set_cloexec_or_close(sv[0]) < 0 || set_cloexec_or_close(sv[1]) < 0)
+               retval = -1;
+
+       return retval;
+}
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd)
 {
 	int newfd;
 
+#ifdef F_DUPFD_CLOEXEC
 	newfd = fcntl(fd, F_DUPFD_CLOEXEC, minfd);
 	if (newfd >= 0)
 		return newfd;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	newfd = fcntl(fd, F_DUPFD, minfd);
 	return set_cloexec_or_close(newfd);
@@ -123,15 +153,18 @@ wl_os_recvmsg_cloexec(int sockfd, struct
 {
 	ssize_t len;
 
+#ifdef MSG_CMSG_CLOEXEC
 	len = recvmsg(sockfd, msg, flags | MSG_CMSG_CLOEXEC);
 	if (len >= 0)
 		return len;
 	if (errno != EINVAL)
 		return -1;
+#endif
 
 	return recvmsg_cloexec_fallback(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void)
 {
@@ -148,6 +181,19 @@ wl_os_epoll_create_cloexec(void)
 	fd = epoll_create(1);
 	return set_cloexec_or_close(fd);
 }
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_kqueue_create_cloexec(void)
+{
+	int fd;
+
+	fd = kqueue();
+
+	return set_cloexec_or_close(fd);
+}
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
