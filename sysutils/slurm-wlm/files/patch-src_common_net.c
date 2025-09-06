--- src/common/net.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/net.c
@@ -75,6 +75,29 @@
 #include "src/common/xstring.h"
 
 /*
+ * Compute correct namelen + sa_len for AF_INET/AF_INET6
+ */
+#if defined(__FreeBSD__)
+static inline socklen_t _bsd_sockaddr_len_fix(struct sockaddr *sa)
+{
+	if (!sa) return 0;
+	switch (sa->sa_family) {
+	case AF_INET: {
+		struct sockaddr_in *in = (struct sockaddr_in *)sa;
+		in->sin_len = (uint8_t)sizeof(*in);
+		return sizeof(*in);
+	}
+	case AF_INET6: {
+		struct sockaddr_in6 *in6 = (struct sockaddr_in6 *)sa;
+		in6->sin6_len = (uint8_t)sizeof(*in6);
+		return sizeof(*in6);
+	}
+	default: return sizeof(*sa);
+	}
+}
+#endif
+
+/*
  * Define slurm-specific aliases for use by plugins, see slurm_xlator.h
  * for details.
  */
@@ -96,12 +119,18 @@ int net_stream_listen(int *fd, uint16_t *port)
 	/* bind ephemeral port */
 	slurm_setup_addr(&sin, 0);
 
+#if defined(__FreeBSD__)
+	socklen_t blen = _bsd_sockaddr_len_fix((struct sockaddr *)&sin);
+#else
+	socklen_t blen = sizeof(sin);
+#endif
 	if ((*fd = socket(sin.ss_family, SOCK_STREAM, IPPROTO_TCP)) < 0)
 		return -1;
 
 	if (setsockopt(*fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0)
 		goto cleanup;
-	if (bind(*fd, (struct sockaddr *) &sin, len) < 0)
+	/* Single bind(): pass platform-correct namelen */
+	if (bind(*fd, (struct sockaddr *) &sin, blen) < 0)
 		goto cleanup;
 	if (getsockname(*fd, (struct sockaddr *) &sin, &len) < 0)
 		goto cleanup;
@@ -219,7 +248,15 @@ static bool _is_port_ok(int s, uint16_t port, bool loc
 		return false;
 	}
 
+/*
+ * compute correct socket length and pass it to bind() as blen on FreeBSD
+ */
+#if defined(__FreeBSD__)
+	socklen_t blen = _bsd_sockaddr_len_fix((struct sockaddr *)&addr);
+	if (bind(s, (struct sockaddr *) &addr, blen) < 0) {
+#else
 	if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
+#endif
 		log_flag(NET, "%s: bind() failed on port:%d fd:%d: %m",
 			 __func__, port, s);
 		return false;
