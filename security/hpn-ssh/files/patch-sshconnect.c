--- sshconnect.c.orig	Fri Apr 13 01:34:36 2001
+++ sshconnect.c	Fri Jun  1 08:01:05 2001
@@ -504,10 +504,12 @@
 		local = (ntohl(((struct sockaddr_in *)hostaddr)->sin_addr.s_addr) >> 24) == IN_LOOPBACKNET;
 		salen = sizeof(struct sockaddr_in);
 		break;
+#ifdef INET6
 	case AF_INET6:
 		local = IN6_IS_ADDR_LOOPBACK(&(((struct sockaddr_in6 *)hostaddr)->sin6_addr));
 		salen = sizeof(struct sockaddr_in6);
 		break;
+#endif
 	default:
 		local = 0;
 		salen = sizeof(struct sockaddr_storage);
