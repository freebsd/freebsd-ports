--- servers/slapd/daemon.c.orig	Thu Apr 24 07:51:08 2003
+++ servers/slapd/daemon.c	Thu Apr 24 07:52:05 2003
@@ -863,6 +863,7 @@
 
 			char	*dnsname = NULL;
 			char	*peeraddr;
+			char	peeraddr6[INET6_ADDRSTRLEN];
 #ifdef LDAP_PF_LOCAL
 			char	peername[MAXPATHLEN + sizeof("PATH=")];
 #elif defined(LDAP_PF_INET6)
@@ -995,12 +996,12 @@
 					 peeraddr != NULL ? peeraddr : "unknown",
 					 (unsigned) ntohs( from.sa_in6_addr.sin6_port ) );
 			} else {
-				char addr[INET6_ADDRSTRLEN];
-				sprintf( peername, "IP=%s %d",
-					 inet_ntop( AF_INET6,
-						    &from.sa_in6_addr.sin6_addr,
-						    addr, sizeof addr) ? addr : "unknown",
+				const char *addr = inet_ntop( AF_INET6,
+																&from.sa_in6_addr.sin6_addr,
+																peeraddr6, sizeof peeraddr6);
+				sprintf( peername, "IP=%s %d", addr ? addr : "unknown",
 					 (unsigned) ntohs( from.sa_in6_addr.sin6_port ) );
+				if (addr) peeraddr = addr;
 			}
 			break;
 #  endif /* LDAP_PF_INET6 */
