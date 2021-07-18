--- csync2.c.orig	2013-05-02 12:58:04 UTC
+++ csync2.c
@@ -256,7 +256,7 @@ static int csync_server_bind(void)
 	struct addrinfo hints;
 	struct addrinfo *result, *rp;
 	int save_errno;
-	int sfd = -1, s, on = 1;
+	int sfd = -1, s, off = 0, on = 1;
 	memset(&hints, 0, sizeof(struct addrinfo));
 	hints.ai_family = AF_UNSPEC;	/* Allow IPv4 or IPv6 */
 	hints.ai_socktype = SOCK_STREAM;
@@ -284,6 +284,9 @@ static int csync_server_bind(void)
 			goto error;
 		if (setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, &on, (socklen_t) sizeof(on)) < 0)
 			goto error;
+		if (rp->ai_family == AF_INET6)
+			if (setsockopt(sfd, IPPROTO_IPV6, IPV6_V6ONLY, &off, (socklen_t) sizeof(off)) < 0)
+				goto error;
 
 		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
 			break;	/* Success */
