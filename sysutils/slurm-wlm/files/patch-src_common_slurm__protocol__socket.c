--- src/common/slurm_protocol_socket.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/slurm_protocol_socket.c
@@ -53,7 +53,9 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <sys/types.h>
+#include <sys/un.h>
 #include <unistd.h>
+#include <fcntl.h>
 
 #include "slurm/slurm_errno.h"
 #include "src/common/read_config.h"
@@ -74,6 +76,28 @@
 #define RANDOM_USER_PORT ((uint16_t) ((lrand48() % \
 		(MAX_USER_PORT - MIN_USER_PORT + 1)) + MIN_USER_PORT))
 
+#if defined(__FreeBSD__)
+/* Normalize sockaddr length on FreeBSD and return the proper namelen */
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
+	default:
+		return sizeof(*sa);
+	}
+}
+#endif
+
 /* Static functions */
 static int _slurm_connect(int __fd, struct sockaddr const * __addr,
 			  socklen_t __len);
@@ -115,8 +139,13 @@ static void _sock_bind_wild(int sockfd)
 
 	slurm_setup_addr(&sin, RANDOM_USER_PORT);
 
+	socklen_t blen = _bsd_sockaddr_len_fix((struct sockaddr *)&sin);
 	for (retry=0; retry < PORT_RETRIES ; retry++) {
+	#if defined(__FreeBSD__)
+		rc = bind(sockfd, (struct sockaddr *) &sin, blen);
+	#else
 		rc = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin));
+	#endif
 		if (rc >= 0)
 			break;
 		slurm_set_port(&sin, RANDOM_USER_PORT);
@@ -511,7 +540,13 @@ extern int slurm_init_msg_engine(slurm_addr_t *addr, b
 		goto error;
 	}
 
-	rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	#if defined(__FreeBSD__)
+		/* FreeBSD: normalize sa_len and pass the exact namelen to bind() */
+		socklen_t bind_len = _bsd_sockaddr_len_fix((struct sockaddr *)addr);
+		rc = bind(fd, (struct sockaddr const *) addr, bind_len);
+	#else
+		rc = bind(fd, (struct sockaddr const *) addr, sizeof(*addr));
+	#endif
 	if (rc < 0) {
 		format_print(log_lvl, "Error binding slurm stream socket: %m");
 		goto error;
@@ -666,7 +701,27 @@ static int _slurm_connect (int __fd, struct sockaddr c
 	if (fcntl(__fd, F_SETFL, flags | O_NONBLOCK) < 0)
 		error("%s: fcntl(F_SETFL) error: %m", __func__);
 
+/* FreeBSD requires correct sa_len/namelen; recompute here */
+#if defined(__FreeBSD__)
+	{
+		struct sockaddr *sa = (struct sockaddr *)__addr;
+		socklen_t namelen;
+		switch (sa->sa_family) {
+		case AF_UNIX: {
+			struct sockaddr_un *un = (struct sockaddr_un *)sa;
+			namelen = (socklen_t)SUN_LEN(un);
+			un->sun_len = (uint8_t)namelen;
+			break;
+		}
+		default:
+			namelen = _bsd_sockaddr_len_fix(sa);
+			break;
+		}
+		rc = connect(__fd, sa, namelen);
+	}
+#else
 	rc = connect(__fd , __addr , __len);
+#endif
 	if ((rc < 0) && (errno != EINPROGRESS))
 		return errno;
 	if (rc == 0)
