--- src/mactelnetd.c.orig	2024-08-15 17:08:22 UTC
+++ src/mactelnetd.c
@@ -254,6 +254,12 @@ static void setup_sockets() {
 				perror("SO_BROADCAST");
 				continue;
 			}
+#if defined(__FreeBSD__)
+			if (setsockopt(interface->socketfd, IPPROTO_IP, IP_ONESBCAST, &optval, sizeof(optval)) == -1) {
+				perror("IP_ONESBCAST");
+				continue;
+			}
+#endif
 
 			setsockopt(interface->socketfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
 
@@ -290,7 +296,7 @@ static int send_udp(const struct mt_connection *conn, 
 		struct sockaddr_in socket_address;
 		socket_address.sin_family = AF_INET;
 		socket_address.sin_port = htons(conn->srcport);
-		socket_address.sin_addr.s_addr = htonl(INADDR_BROADCAST);
+		memcpy(&(socket_address.sin_addr), &conn->interface->bcast_addr, IPV4_ALEN);
 
 		return sendto(conn->interface->socketfd, packet->data, packet->size, 0, (struct sockaddr *)&socket_address,
 					  sizeof(socket_address));
@@ -315,7 +321,7 @@ static int send_special_udp(struct net_interface *inte
 		struct sockaddr_in socket_address;
 		socket_address.sin_family = AF_INET;
 		socket_address.sin_port = htons(port);
-		socket_address.sin_addr.s_addr = htonl(INADDR_BROADCAST);
+		memcpy(&(socket_address.sin_addr), &interface->bcast_addr, IPV4_ALEN);
 
 		return sendto(interface->socketfd, packet->data, packet->size, 0, (struct sockaddr *)&socket_address,
 					  sizeof(socket_address));
