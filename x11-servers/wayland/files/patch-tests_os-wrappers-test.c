--- tests/os-wrappers-test.c.orig	2015-07-06 19:38:51 UTC
+++ tests/os-wrappers-test.c
@@ -26,6 +26,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <assert.h>
 #include <sys/types.h>
@@ -37,7 +39,13 @@
 #include <stdarg.h>
 #include <fcntl.h>
 #include <stdio.h>
+
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#elif HAVE_SYS_EVENT_H
+#include <sys/event.h>
+#include <sys/types.h>
+#endif
 
 #include "wayland-private.h"
 #include "test-runner.h"
@@ -54,8 +62,13 @@ static int wrapped_calls_fcntl;
 static ssize_t (*real_recvmsg)(int, struct msghdr *, int);
 static int wrapped_calls_recvmsg;
 
+#ifdef HAVE_SYS_EPOLL_H
 static int (*real_epoll_create1)(int);
 static int wrapped_calls_epoll_create1;
+#elif HAVE_SYS_EVENT_H
+static int (*real_kqueue)(void);
+static int wrapped_calls_kqueue;
+#endif
 
 static void
 init_fallbacks(int do_fallbacks)
@@ -64,7 +77,11 @@ init_fallbacks(int do_fallbacks)
 	real_socket = dlsym(RTLD_NEXT, "socket");
 	real_fcntl = dlsym(RTLD_NEXT, "fcntl");
 	real_recvmsg = dlsym(RTLD_NEXT, "recvmsg");
+#ifdef HAVE_SYS_EPOLL_H
 	real_epoll_create1 = dlsym(RTLD_NEXT, "epoll_create1");
+#elif HAVE_SYS_EVENT_H
+	real_kqueue = dlsym(RTLD_NEXT, "kqueue");
+#endif
 }
 
 __attribute__ ((visibility("default"))) int
@@ -72,10 +89,12 @@ socket(int domain, int type, int protoco
 {
 	wrapped_calls_socket++;
 
+#ifdef SOCK_CLOEXEC
 	if (fall_back && (type & SOCK_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_socket(domain, type, protocol);
 }
@@ -88,10 +107,12 @@ fcntl(int fd, int cmd, ...)
 
 	wrapped_calls_fcntl++;
 
+#ifdef F_DUPFD_CLOEXEC
 	if (fall_back && (cmd == F_DUPFD_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	va_start(ap, cmd);
 	arg = va_arg(ap, void*);
@@ -105,14 +126,17 @@ recvmsg(int sockfd, struct msghdr *msg, 
 {
 	wrapped_calls_recvmsg++;
 
+#ifdef MSG_CMSG_CLOEXEC
 	if (fall_back && (flags & MSG_CMSG_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_recvmsg(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 __attribute__ ((visibility("default"))) int
 epoll_create1(int flags)
 {
@@ -126,6 +150,15 @@ epoll_create1(int flags)
 
 	return real_epoll_create1(flags);
 }
+#elif HAVE_SYS_EVENT_H
+__attribute__ ((visibility("default"))) int
+kqueue(void)
+{
+       wrapped_calls_kqueue++;
+
+       return real_kqueue();
+}
+#endif
 
 static void
 do_os_wrappers_socket_cloexec(int n)
@@ -155,12 +188,14 @@ TEST(os_wrappers_socket_cloexec)
 	do_os_wrappers_socket_cloexec(0);
 }
 
+#ifdef SOCK_CLOEXEC
 TEST(os_wrappers_socket_cloexec_fallback)
 {
 	/* forced fallback */
 	init_fallbacks(1);
 	do_os_wrappers_socket_cloexec(1);
 }
+#endif
 
 static void
 do_os_wrappers_dupfd_cloexec(int n)
@@ -194,11 +229,13 @@ TEST(os_wrappers_dupfd_cloexec)
 	do_os_wrappers_dupfd_cloexec(0);
 }
 
+#ifdef F_DUPFD_CLOEXEC
 TEST(os_wrappers_dupfd_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_dupfd_cloexec(3);
 }
+#endif
 
 struct marshal_data {
 	struct wl_connection *read_connection;
@@ -217,8 +254,7 @@ struct marshal_data {
 static void
 setup_marshal_data(struct marshal_data *data)
 {
-	assert(socketpair(AF_UNIX,
-			  SOCK_STREAM | SOCK_CLOEXEC, 0, data->s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, data->s) == 0);
 
 	data->read_connection = wl_connection_create(data->s[0]);
 	assert(data->read_connection);
@@ -327,11 +363,13 @@ TEST(os_wrappers_recvmsg_cloexec)
 	do_os_wrappers_recvmsg_cloexec(0);
 }
 
+#ifdef MSG_CMSG_CLOEXEC
 TEST(os_wrappers_recvmsg_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_recvmsg_cloexec(1);
 }
+#endif
 
 static void
 do_os_wrappers_epoll_create_cloexec(int n)
@@ -341,12 +379,20 @@ do_os_wrappers_epoll_create_cloexec(int 
 
 	nr_fds = count_open_fds();
 
+#ifdef HAVE_SYS_EPOLL_H
 	fd = wl_os_epoll_create_cloexec();
+#elif HAVE_SYS_EVENT_H
+	fd = wl_os_kqueue_create_cloexec();
+#endif
 	assert(fd >= 0);
 
 #ifdef EPOLL_CLOEXEC
+#ifdef HAVE_SYS_EPOLL_H
 	assert(wrapped_calls_epoll_create1 == n);
 #else
+	assert(wrapped_calls_kqueue == n);
+#endif
+#else
 	printf("No epoll_create1.\n");
 #endif
 
