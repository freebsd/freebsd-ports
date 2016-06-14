--- mcgroup.c.orig	2016-02-17 21:02:06 UTC
+++ mcgroup.c
@@ -54,11 +54,23 @@ static struct iface *find_valid_iface(co
 static void mcgroup4_init(void)
 {
 	if (mcgroup4_socket < 0) {
+#ifdef SOCK_CLOEXEC
 		mcgroup4_socket = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
+#else
+		mcgroup4_socket = socket(AF_INET, SOCK_DGRAM, 0);
+#endif
 		if (mcgroup4_socket < 0) {
 			smclog(LOG_ERR, "Failed creating socket for joining IPv4 multicast groups: %m");
 			exit(255);
 		}
+#ifndef SOCK_CLOEXEC
+		if (fcntl(mcgroup4_socket, F_SETFD, FD_CLOEXEC) < 0) {
+			smclog(LOG_WARNING, "Failed creating socket for joining IPv4 multicast groups: %m");
+			close(mcgroup4_socket);
+			mcgroup4_socket = -1;
+			return;
+		}
+#endif
 
 #ifdef __linux__
 		if (setsockopt(mcgroup4_socket, SOL_SOCKET, SO_ATTACH_FILTER, &fprog, sizeof(fprog)) < 0)
@@ -132,11 +144,23 @@ static int mcgroup6_socket = -1;
 static void mcgroup6_init(void)
 {
 	if (mcgroup6_socket < 0) {
+#ifdef SOCK_CLOEXEC
 		mcgroup6_socket = socket(AF_INET6, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
+#else
+		mcgroup6_socket = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
+#endif
 		if (mcgroup6_socket < 0) {
 			smclog(LOG_WARNING, "Failed creating socket for joining IPv6 multicast groups: %m");
 			return;
 		}
+#ifndef SOCK_CLOEXEC
+		if (fcntl(mcgroup6_socket, F_SETFD, FD_CLOEXEC) < 0) {
+			smclog(LOG_WARNING, "Failed creating socket for joining IPv6 multicast groups: %m");
+			close(mcgroup6_socket);
+			mcgroup6_socket = -1;
+			return;
+		}
+#endif
 
 #ifdef __linux__
 		if (setsockopt(mcgroup6_socket, SOL_SOCKET, SO_ATTACH_FILTER, &fprog, sizeof(fprog)) < 0)
