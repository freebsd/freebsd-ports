--- src/mactelnet.c.orig	2024-08-15 16:46:24 UTC
+++ src/mactelnet.c
@@ -126,6 +126,8 @@ unsigned char mt_direction_fromserver = 0;
 
 static unsigned int send_socket;
 
+static unsigned char *bcast_addr;
+
 static int handle_packet(unsigned char *data, int data_len);
 
 static void print_version() {
@@ -168,7 +170,7 @@ static int send_udp(struct mt_packet *packet, int retr
 		struct sockaddr_in socket_address;
 		socket_address.sin_family = AF_INET;
 		socket_address.sin_port = htons(MT_MACTELNET_PORT);
-		socket_address.sin_addr.s_addr = htonl(INADDR_BROADCAST);
+		memcpy(&(socket_address.sin_addr), bcast_addr, IPV4_ALEN);
 
 		sent_bytes = sendto(send_socket, packet->data, packet->size, 0, (struct sockaddr *)&socket_address,
 							sizeof(socket_address));
@@ -470,6 +472,9 @@ static int find_interface() {
 			continue;
 		}
 
+#if defined(__FreeBSD__)
+		setsockopt(testsocket, IPPROTO_IP, IP_ONESBCAST, &optval, sizeof(optval));
+#endif
 		setsockopt(testsocket, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));
 		setsockopt(testsocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
 
@@ -488,6 +493,7 @@ static int find_interface() {
 		send_socket = testsocket;
 		memcpy(srcmac, interface->mac_addr, ETH_ALEN);
 		active_interface = interface;
+		bcast_addr = interface->bcast_addr;
 
 		/* Send a SESSIONSTART message with the current device */
 		init_packet(&data, MT_PTYPE_SESSIONSTART, srcmac, dstmac, sessionkey, 0);
