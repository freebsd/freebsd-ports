--- src/dns.c.orig	2015-09-14 15:41:48.002439000 +0300
+++ src/dns.c	2015-09-14 15:43:01.499844000 +0300
@@ -848,7 +848,7 @@ int dns_init_resolvers(void)
 			}
 
 			/* "connect" the UDP socket to the name server IP */
-			if (connect(fd, (struct sockaddr*)&curnameserver->addr, sizeof(curnameserver->addr)) == -1) {
+			if (connect(fd, (struct sockaddr*)&curnameserver->addr, get_addr_len(&curnameserver->addr)) == -1) {
 				Alert("Starting [%s/%s] nameserver: can't connect socket.\n", curr_resolvers->id,
 						curnameserver->id);
 				close(fd);
