--- sshconnect.c.orig	Wed Jun 19 02:27:55 2002
+++ sshconnect.c	Fri Jun 21 23:02:29 2002
@@ -279,7 +279,11 @@
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
@@ -516,10 +520,12 @@
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
