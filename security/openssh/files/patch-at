--- sshconnect.c.orig	Mon Jan 21 16:13:51 2002
+++ sshconnect.c	Fri Mar  8 18:14:50 2002
@@ -43,15 +43,21 @@
 sockaddr_ntop(struct sockaddr *sa)
 {
 	void *addr;
+#ifdef INET6
 	static char addrbuf[INET6_ADDRSTRLEN];
+#else
+	static char addrbuf[INET_ADDRSTRLEN];
+#endif
 
 	switch (sa->sa_family) {
 	case AF_INET:
 		addr = &((struct sockaddr_in *)sa)->sin_addr;
 		break;
+#ifdef INET6
 	case AF_INET6:
 		addr = &((struct sockaddr_in6 *)sa)->sin6_addr;
 		break;
+#endif
 	default:
 		/* This case should be protected against elsewhere */
 		abort();	/* XXX abort is bad -- do something else */
@@ -291,7 +297,11 @@
 		/* Loop through addresses for this host, and try each one in
 		   sequence until the connection succeeds. */
 		for (ai = aitop; ai; ai = ai->ai_next) {
+#ifdef INET6
 			if (ai->ai_family != AF_INET && ai->ai_family != AF_INET6)
+#else
+			if (ai->ai_family != AF_INET)
+#endif
 				continue;
 			if (getnameinfo(ai->ai_addr, ai->ai_addrlen,
 			    ntop, sizeof(ntop), strport, sizeof(strport),
@@ -537,10 +547,12 @@
 		local = (ntohl(((struct sockaddr_in *)hostaddr)->
 		   sin_addr.s_addr) >> 24) == IN_LOOPBACKNET;
 		break;
+#ifdef INET6
 	case AF_INET6:
 		local = IN6_IS_ADDR_LOOPBACK(
 		    &(((struct sockaddr_in6 *)hostaddr)->sin6_addr));
 		break;
+#endif
 	default:
 		local = 0;
 		break;
