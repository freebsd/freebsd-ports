--- src/main-ban.c.orig	2023-12-17 10:19:23 UTC
+++ src/main-ban.c
@@ -407,8 +407,8 @@ static bool test_local_ipv6(struct sockaddr_in6 * remo
 	unsigned index = 0;
 
 	for (index = 0; index < 4; index ++) {
-		uint32_t l = local->sin6_addr.s6_addr32[index] & network->sin6_addr.s6_addr32[index];
-		uint32_t r = remote->sin6_addr.s6_addr32[index] & network->sin6_addr.s6_addr32[index];
+		uint32_t l = local->sin6_addr.__u6_addr.__u6_addr32[index] & network->sin6_addr.__u6_addr.__u6_addr32[index];
+		uint32_t r = remote->sin6_addr.__u6_addr.__u6_addr32[index] & network->sin6_addr.__u6_addr.__u6_addr32[index];
 		if (l != r)
 			return false;
 	}
