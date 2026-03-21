--- src/common/slurm_protocol_socket.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/slurm_protocol_socket.c
@@ -64,6 +64,7 @@
 #include "src/common/read_config.h"
 #include "src/common/slurm_protocol_api.h"
 #include "src/common/slurm_protocol_socket.h"
+#include "src/common/slurm_sockaddr.h"
 #include "src/common/slurm_time.h"
 #include "src/common/strlcpy.h"
 #include "src/common/util-net.h"
@@ -107,7 +108,9 @@ static void _sock_bind_wild(int sockfd)
 	slurm_setup_addr(&sin, RANDOM_USER_PORT);
 
 	for (retry=0; retry < PORT_RETRIES ; retry++) {
-		rc = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin));
+		socklen_t blen = slurm_sockaddr_fixlen(
+		    (struct sockaddr *)&sin, (socklen_t)sizeof(sin));
+		rc = bind(sockfd, (struct sockaddr *)&sin, blen);
 		if (rc >= 0)
 			break;
 		slurm_set_port(&sin, RANDOM_USER_PORT);
@@ -543,26 +546,30 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr, b
 
 extern int slurm_init_msg_engine(slurm_addr_t *addr, bool quiet)
 {
-	socklen_t bind_len = (addr->ss_family == AF_INET6) ?
-				     sizeof(struct sockaddr_in6) :
-				     sizeof(struct sockaddr_in);
 	int rc;
 	int fd;
 	int log_lvl = LOG_LEVEL_ERROR;
 	const int one = 1;
 	const size_t sz1 = sizeof(one);
+	socklen_t bind_len = slurm_sockaddr_fixlen((struct sockaddr *)addr,
+			    (socklen_t)sizeof(*addr));
+
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
-	/*
-	 * The BSDs requires the sa_len field to be set correctly in
-	 * struct sockaddr_in / sockaddr_in6 before calling bind().
-	 * If unset, bind() may fail with EINVAL.
-	 */
+/*
+ * Fallback: if configure didn't detect any sockaddr length fields,
+ * preserve the historical BSD workaround.
+ */
+#if !defined(HAVE_STRUCT_SOCKADDR_IN_SIN_LEN) && \
+    !defined(HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN) && \
+    !defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
 	if (addr->ss_family == AF_INET)
-		((struct sockaddr_in *) addr)->sin_len = bind_len;
+		((struct sockaddr_in *)addr)->sin_len =
+			(uint8_t)sizeof(struct sockaddr_in);
 	else if (addr->ss_family == AF_INET6)
-		((struct sockaddr_in6 *) addr)->sin6_len = bind_len;
+		((struct sockaddr_in6 *)addr)->sin6_len =
+			(uint8_t)sizeof(struct sockaddr_in6);
 #endif
-
+#endif
 	if (quiet)
 		log_lvl = LOG_LEVEL_DEBUG;
 
@@ -688,8 +695,10 @@ extern int slurm_open_stream(slurm_addr_t *addr, bool 
 			_sock_bind_wild(fd);
 		}
 
-		rc = _slurm_connect(fd, (struct sockaddr const *)addr,
-				    sizeof(*addr));
+		slurm_addr_t tmp = *addr;
+		socklen_t alen = slurm_sockaddr_fixlen(
+		    (struct sockaddr *)&tmp, (socklen_t)sizeof(tmp));
+		rc = _slurm_connect(fd, (struct sockaddr const *)&tmp, alen);
 		if (!rc) {
 			/* success */
 			break;
@@ -756,8 +765,10 @@ extern int slurm_open_unix_stream(char *addr_name, int
 	memset(&sa, 0, sizeof(sa));
 	sa.sun_family = AF_UNIX;
 	strcpy(sa.sun_path, addr_name);
+	socklen_t slen = slurm_sockaddr_fixlen((struct sockaddr *)&sa,
+					       (socklen_t)sizeof(sa));
 
-	while ((rc = connect(*fd, (struct sockaddr *) &sa, SUN_LEN(&sa))) &&
+	while ((rc = connect(*fd, (struct sockaddr *)&sa, slen)) &&
 	       (errno == EINTR))
 		; /* empty loop */
 
