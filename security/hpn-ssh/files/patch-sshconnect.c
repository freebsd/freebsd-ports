--- sshconnect.c.orig	Wed Aug  8 00:29:09 2001
+++ sshconnect.c	Wed Oct  3 14:28:15 2001
@@ -577,11 +577,13 @@
 		    sin_addr.s_addr) >> 24) == IN_LOOPBACKNET;
 		salen = sizeof(struct sockaddr_in);
 		break;
+#ifdef INET6
 	case AF_INET6:
 		local = IN6_IS_ADDR_LOOPBACK(
 		    &(((struct sockaddr_in6 *)hostaddr)->sin6_addr));
 		salen = sizeof(struct sockaddr_in6);
 		break;
+#endif
 	default:
 		local = 0;
 		salen = sizeof(struct sockaddr_storage);
