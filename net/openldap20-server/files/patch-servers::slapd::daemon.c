#
# ITS#1918: slapd panics with real ipv6 addresses
#
--- servers/slapd/daemon.c.orig	Tue Sep 23 17:21:54 2003
+++ servers/slapd/daemon.c	Tue Sep 23 17:25:02 2003
@@ -996,10 +996,12 @@
 					 (unsigned) ntohs( from.sa_in6_addr.sin6_port ) );
 			} else {
 				char addr[INET6_ADDRSTRLEN];
+
+				peeraddr = (char *) inet_ntop( AF_INET6,
+						      &from.sa_in6_addr.sin6_addr,
+						      addr, sizeof addr );
 				sprintf( peername, "IP=%s %d",
-					 inet_ntop( AF_INET6,
-						    &from.sa_in6_addr.sin6_addr,
-						    addr, sizeof addr) ? addr : "unknown",
+					 peeraddr != NULL ? peeraddr : "unknown",
 					 (unsigned) ntohs( from.sa_in6_addr.sin6_port ) );
 			}
 			break;
