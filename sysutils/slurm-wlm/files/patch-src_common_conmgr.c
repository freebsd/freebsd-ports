--- src/common/conmgr.c.orig	2024-05-21 17:19:51 UTC
+++ src/common/conmgr.c
@@ -47,6 +47,8 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#include <sys/param.h>
+#include <sys/ucred.h>
 #include <time.h>
 #include <unistd.h>
 
@@ -2616,8 +2618,15 @@ static int _create_socket(void *x, void *arg)
 
 		/* set value of socket path */
 		strlcpy(addr.sun_path, unixsock, sizeof(addr.sun_path));
-		if ((rc = bind(fd, (const struct sockaddr *) &addr,
-			       sizeof(addr))))
+		/* Bind UNIX socket: compute correct length */
+		{
+			socklen_t len = SUN_LEN(&addr);
+		#if defined(__FreeBSD__)
+			addr.sun_len = (uint8_t)len;
+		#endif
+			rc = bind(fd, (const struct sockaddr *)&addr, len);
+		}
+		if (rc)
 			fatal("%s: [%s] Unable to bind UNIX socket: %m",
 			      __func__, hostport);
 
@@ -2675,6 +2684,19 @@ static int _create_socket(void *x, void *arg)
 			       &one, sizeof(one)))
 			fatal("%s: [%s] setsockopt(SO_REUSEADDR) failed: %m",
 			      __func__, addrinfo_to_string(addr));
+
+		/* For INET/INET6, set *_len on FreeBSD; ai_addrlen is already correct */
+		#if defined(__FreeBSD__)
+			if (addr->ai_addr) {
+				if (addr->ai_addr->sa_family == AF_INET) {
+					((struct sockaddr_in *)addr->ai_addr)->sin_len =
+					    (uint8_t)sizeof(struct sockaddr_in);
+				} else if (addr->ai_addr->sa_family == AF_INET6) {
+					((struct sockaddr_in6 *)addr->ai_addr)->sin6_len =
+					    (uint8_t)sizeof(struct sockaddr_in6);
+				}
+			}
+		#endif
 
 		if (bind(fd, addr->ai_addr, addr->ai_addrlen) != 0)
 			fatal("%s: [%s] Unable to bind socket: %m",
