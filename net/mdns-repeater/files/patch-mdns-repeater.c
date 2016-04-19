--- mdns-repeater.c.orig	2015-04-03 07:03:21 UTC
+++ mdns-repeater.c
@@ -32,6 +32,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <net/if.h>
+#include <errno.h>
 
 #define PACKAGE "mdns-repeater"
 #define MDNS_ADDR "224.0.0.251"
@@ -79,7 +80,7 @@ void log_message(int loglevel, char *fmt
 static int create_recv_sock() {
 	int sd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (sd < 0) {
-		log_message(LOG_ERR, "recv socket(): %m");
+		log_message(LOG_ERR, "recv socket(): %s", strerror(errno));
 		return sd;
 	}
 
@@ -87,7 +88,7 @@ static int create_recv_sock() {
 
 	int on = 1;
 	if ((r = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0) {
-		log_message(LOG_ERR, "recv setsockopt(SO_REUSEADDR): %m");
+		log_message(LOG_ERR, "recv setsockopt(SO_REUSEADDR): %s", strerror(errno));
 		return r;
 	}
 
@@ -98,18 +99,18 @@ static int create_recv_sock() {
 	serveraddr.sin_port = htons(MDNS_PORT);
 	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);	/* receive multicast */
 	if ((r = bind(sd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0) {
-		log_message(LOG_ERR, "recv bind(): %m");
+		log_message(LOG_ERR, "recv bind(): %s", strerror(errno));
 	}
 
 	// enable loopback in case someone else needs the data
 	if ((r = setsockopt(sd, IPPROTO_IP, IP_MULTICAST_LOOP, &on, sizeof(on))) < 0) {
-		log_message(LOG_ERR, "recv setsockopt(IP_MULTICAST_LOOP): %m");
+		log_message(LOG_ERR, "recv setsockopt(IP_MULTICAST_LOOP): %s", strerror(errno));
 		return r;
 	}
 
 #ifdef IP_PKTINFO
 	if ((r = setsockopt(sd, SOL_IP, IP_PKTINFO, &on, sizeof(on))) < 0) {
-		log_message(LOG_ERR, "recv setsockopt(IP_PKTINFO): %m");
+		log_message(LOG_ERR, "recv setsockopt(IP_PKTINFO): %s", strerror(errno));
 		return r;
 	}
 #endif
@@ -120,7 +121,7 @@ static int create_recv_sock() {
 static int create_send_sock(int recv_sockfd, const char *ifname, struct if_sock *sockdata) {
 	int sd = socket(AF_INET, SOCK_DGRAM, 0);
 	if (sd < 0) {
-		log_message(LOG_ERR, "send socket(): %m");
+		log_message(LOG_ERR, "send socket(): %s", strerror(errno));
 		return sd;
 	}
 
@@ -136,7 +137,7 @@ static int create_send_sock(int recv_soc
 
 #ifdef SO_BINDTODEVICE
 	if ((r = setsockopt(sd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(struct ifreq))) < 0) {
-		log_message(LOG_ERR, "send setsockopt(SO_BINDTODEVICE): %m");
+		log_message(LOG_ERR, "send setsockopt(SO_BINDTODEVICE): %s", strerror(errno));
 		return r;
 	}
 #endif
@@ -156,7 +157,7 @@ static int create_send_sock(int recv_soc
 
 	int on = 1;
 	if ((r = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0) {
-		log_message(LOG_ERR, "send setsockopt(SO_REUSEADDR): %m");
+		log_message(LOG_ERR, "send setsockopt(SO_REUSEADDR): %s", strerror(errno));
 		return r;
 	}
 
@@ -167,22 +168,28 @@ static int create_send_sock(int recv_soc
 	serveraddr.sin_port = htons(MDNS_PORT);
 	serveraddr.sin_addr.s_addr = if_addr->s_addr;
 	if ((r = bind(sd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) < 0) {
-		log_message(LOG_ERR, "send bind(): %m");
+		log_message(LOG_ERR, "send bind(): %s", strerror(errno));
 	}
 
+#if __FreeBSD__
+	if((r = setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, &serveraddr.sin_addr, sizeof(serveraddr.sin_addr))) < 0) {
+		log_message(LOG_ERR, "send ip_multicast_if(): errno %d: %s", errno, strerror(errno));
+	}
+#endif
+
 	// add membership to receiving socket
 	struct ip_mreq mreq;
 	memset(&mreq, 0, sizeof(struct ip_mreq));
 	mreq.imr_interface.s_addr = if_addr->s_addr;
 	mreq.imr_multiaddr.s_addr = inet_addr(MDNS_ADDR);
 	if ((r = setsockopt(recv_sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq))) < 0) {
-		log_message(LOG_ERR, "recv setsockopt(IP_ADD_MEMBERSHIP): %m");
+		log_message(LOG_ERR, "recv setsockopt(IP_ADD_MEMBERSHIP): %s", strerror(errno));
 		return r;
 	}
 
 	// enable loopback in case someone else needs the data
 	if ((r = setsockopt(sd, IPPROTO_IP, IP_MULTICAST_LOOP, &on, sizeof(on))) < 0) {
-		log_message(LOG_ERR, "send setsockopt(IP_MULTICAST_LOOP): %m");
+		log_message(LOG_ERR, "send setsockopt(IP_MULTICAST_LOOP): %s", strerror(errno));
 		return r;
 	}
 
@@ -249,7 +256,7 @@ static void daemonize() {
 	pid_t running_pid;
 	pid_t pid = fork();
 	if (pid < 0) {
-		log_message(LOG_ERR, "fork(): %m");
+		log_message(LOG_ERR, "fork(): %s", strerror(errno));
 		exit(1);
 	}
 
@@ -385,7 +392,7 @@ int main(int argc, char *argv[]) {
 
 	pkt_data = malloc(PACKET_SIZE);
 	if (pkt_data == NULL) {
-		log_message(LOG_ERR, "cannot malloc() packet buffer: %m");
+		log_message(LOG_ERR, "cannot malloc() packet buffer: %s", strerror(errno));
 		r = 1;
 		goto end_main;
 	}
@@ -409,7 +416,7 @@ int main(int argc, char *argv[]) {
 			ssize_t recvsize = recvfrom(server_sockfd, pkt_data, PACKET_SIZE, 0, 
 				(struct sockaddr *) &fromaddr, &sockaddr_size);
 			if (recvsize < 0) {
-				log_message(LOG_ERR, "recv(): %m");
+				log_message(LOG_ERR, "recv(): %s", strerror(errno));
 			}
 
 			int j;
@@ -440,7 +447,7 @@ int main(int argc, char *argv[]) {
 				ssize_t sentsize = send_packet(socks[j].sockfd, pkt_data, (size_t) recvsize);
 				if (sentsize != recvsize) {
 					if (sentsize < 0)
-						log_message(LOG_ERR, "send()");
+						log_message(LOG_ERR, "send(): %s", strerror(errno));
 					else
 						log_message(LOG_ERR, "send_packet size differs: sent=%ld actual=%ld",
 							recvsize, sentsize);
