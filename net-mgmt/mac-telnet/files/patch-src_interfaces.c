--- src/interfaces.c.orig	2024-08-15 15:58:48 UTC
+++ src/interfaces.c
@@ -150,6 +150,9 @@ int net_get_interfaces(struct net_interface **interfac
 	static const struct ifaddrs *ifaddrsp;
 	const struct sockaddr_in *dl_addr;
 	int found = 0;
+#if !defined(__FreeBSD__)
+	long allones_bcast = htonl(INADDR_BROADCAST);
+#endif
 
 	if (getifaddrs(&int_addrs) < 0) {
 		perror("getifaddrs");
@@ -173,8 +176,14 @@ int net_get_interfaces(struct net_interface **interfac
 
 				if (ifaddrsp->ifa_addr->sa_family == AF_INET) {
 					memcpy(interface->ipv4_addr, &dl_addr->sin_addr, IPV4_ALEN);
+#if defined(__FreeBSD__)
+					memcpy(interface->bcast_addr, &((const struct sockaddr_in *)ifaddrsp->ifa_broadaddr)->sin_addr, IPV4_ALEN);
+#else
+					memcpy(interface->bcast_addr, &allones_bcast, IPV4_ALEN);
+#endif
 				} else {
 					memset(interface->ipv4_addr, 0, IPV4_ALEN);
+					memset(interface->bcast_addr, 0, IPV4_ALEN);
 				}
 			}
 #ifdef __linux__
@@ -208,9 +217,12 @@ int net_get_interfaces(struct net_interface **interfac
 		DL_FOREACH(*interfaces, interface) {
 			struct in_addr *addr =
 			  (struct in_addr *)interface->ipv4_addr;
+			struct in_addr *bcast =
+			  (struct in_addr *)interface->bcast_addr;
 
 			printf("Interface %s:\n", interface->name);
 			printf("\tIP: %s\n", inet_ntoa(*addr));
+			printf("\tBCAST: %s\n", inet_ntoa(*bcast));
 			printf("\tMAC: %s\n",
 			  ether_ntoa((struct ether_addr *)interface->mac_addr));
 #ifdef __linux__
