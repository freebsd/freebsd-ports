--- mroute-api.c.orig	2016-02-17 21:02:06 UTC
+++ mroute-api.c
@@ -98,13 +98,26 @@ int mroute4_enable(void)
 	unsigned int i;
 	struct iface *iface;
 
+#ifdef SOCK_CLOEXEC
 	mroute4_socket = socket(AF_INET, SOCK_RAW | SOCK_CLOEXEC, IPPROTO_IGMP);
+#else
+	mroute4_socket = socket(AF_INET, SOCK_RAW, IPPROTO_IGMP);
+#endif
 	if (mroute4_socket < 0) {
 		if (ENOPROTOOPT == errno)
 			smclog(LOG_WARNING, "Kernel does not support IPv4 multicast routing, skipping ...");
 
 		return -1;
 	}
+#ifndef SOCK_CLOEXEC
+	if (fcntl(mroute4_socket, F_SETFD, FD_CLOEXEC) < 0) {
+		smclog(LOG_INIT, "Failed initializing IPv4 multicast routing API: %m");
+		close(mroute4_socket);
+		mroute4_socket = -1;
+
+		return -1;
+	}
+#endif
 
 	if (setsockopt(mroute4_socket, IPPROTO_IP, MRT_INIT, (void *)&arg, sizeof(arg))) {
 		switch (errno) {
@@ -472,12 +485,25 @@ int mroute6_enable(void)
 	unsigned int i;
 	struct iface *iface;
 
+#ifdef SOCK_CLOEXEC
 	if ((mroute6_socket = socket(AF_INET6, SOCK_RAW | SOCK_CLOEXEC, IPPROTO_ICMPV6)) < 0) {
+#else
+	if ((mroute6_socket = socket(AF_INET6, SOCK_RAW, IPPROTO_ICMPV6)) < 0) {
+#endif
 		if (ENOPROTOOPT == errno)
 			smclog(LOG_WARNING, "Kernel does not support IPv6 multicast routing, skipping ...");
 
 		return -1;
 	}
+#ifndef SOCK_CLOEXEC
+	if (fcntl(mroute6_socket, F_SETFD, FD_CLOEXEC) < 0) {
+		smclog(LOG_INIT, "Failed initializing IPv6 multicast routing API: %m");
+		close(mroute6_socket);
+		mroute6_socket = -1;
+
+		return -1;
+	}
+#endif
 	if (setsockopt(mroute6_socket, IPPROTO_IPV6, MRT6_INIT, (void *)&arg, sizeof(arg))) {
 		switch (errno) {
 		case EADDRINUSE:
