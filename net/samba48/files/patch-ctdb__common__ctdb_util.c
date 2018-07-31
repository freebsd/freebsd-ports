--- ctdb/common/ctdb_util.c.orig	2018-06-28 15:36:39 UTC
+++ ctdb/common/ctdb_util.c
@@ -390,7 +390,7 @@ void ctdb_canonicalize_ip(const ctdb_soc
 		} else {
 			cip->ip6.sin6_family = AF_INET6;
 #ifdef HAVE_SOCK_SIN_LEN
-			cip->ip6.sin_len = sizeof(ctdb_sock_addr);
+			cip->ip6.sin6_len = sizeof(ctdb_sock_addr);
 #endif
 			cip->ip6.sin6_port   = ip->ip6.sin6_port;
 			memcpy(&cip->ip6.sin6_addr,
