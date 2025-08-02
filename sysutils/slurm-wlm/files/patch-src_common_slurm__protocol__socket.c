--- src/common/slurm_protocol_socket.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/slurm_protocol_socket.c
@@ -491,6 +491,27 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr, b
 extern int slurm_init_msg_engine(slurm_addr_t *addr, bool quiet)
 {
 	int rc;
+
+	#if defined(__FreeBSD__)
+		/*
+		 * FreeBSD requires the sa_len field to be set correctly in
+		 * struct sockaddr_in / sockaddr_in6 before calling bind().
+		 * If it is unset, bind() may fail with EINVAL.
+		 *
+		 * This adjustment ensures the correct length is set based
+		 * on the address family before bind() is called.
+		 */
+		if (addr->ss_family == AF_INET) {
+			((struct sockaddr_in *)addr)->sin_len = sizeof(struct sockaddr_in);
+		} else if (addr->ss_family == AF_INET6) {
+			((struct sockaddr_in6 *)addr)->sin6_len = sizeof(struct sockaddr_in6);
+		}
+
+		/* Track the correct length for bind() */
+		socklen_t bind_len = (addr->ss_family == AF_INET6)
+			? sizeof(struct sockaddr_in6) : sizeof(struct sockaddr_in);
+	#endif
+
 	int fd;
 	int log_lvl = LOG_LEVEL_ERROR;
 	const int one = 1;
@@ -511,7 +532,11 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr, b
 		goto error;
 	}
 
-	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	#if defined(__FreeBSD__)
+		rc = bind(fd, (struct sockaddr const *) addr, bind_len);
+	#else
+		rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	#endif
 	if (rc < 0) {
 		format_print(log_lvl, "Error binding slurm stream socket: %m");
 		goto error;
