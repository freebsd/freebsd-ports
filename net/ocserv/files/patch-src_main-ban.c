--- src/main-ban.c.orig	2021-01-26 17:01:03 UTC
+++ src/main-ban.c
@@ -403,8 +403,8 @@ static bool test_local_ipv6(struct sockaddr_in6 * remo
 	unsigned index = 0;
 	
 	for (index = 0; index < 4; index ++) {
-		uint32_t l = local->sin6_addr.s6_addr32[index] & network->sin6_addr.s6_addr32[index];
-		uint32_t r = remote->sin6_addr.s6_addr32[index] & network->sin6_addr.s6_addr32[index];
+		uint32_t l = local->sin6_addr.__u6_addr.__u6_addr32[index] & network->sin6_addr.__u6_addr.__u6_addr32[index];
+		uint32_t r = remote->sin6_addr.__u6_addr.__u6_addr32[index] & network->sin6_addr.__u6_addr.__u6_addr32[index];
 		if (l != r) 
 			return false;
 	}
@@ -443,4 +443,4 @@ void if_address_cleanup(main_server_st * s)
 
 	s->if_addresses = NULL;
 	s->if_addresses_count = 0;
-}
\ No newline at end of file
+}
