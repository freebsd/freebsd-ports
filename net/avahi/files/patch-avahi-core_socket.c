--- avahi-core/socket.c.orig	Thu Feb  9 20:45:09 2006
+++ avahi-core/socket.c	Mon Apr 24 17:14:18 2006
@@ -468,7 +468,7 @@ int avahi_send_dns_packet_ipv4(int fd, A
     size_t cmsg_data[( CMSG_SPACE(sizeof(struct in_pktinfo)) / sizeof(size_t)) + 1];
 #elif defined(IP_SENDSRCADDR)
     struct cmsghdr *cmsg;
-    size_t cmsg_data[( CMSG_SPACE(sizeof(struct in_addr)) / sizeof(size_t)) + 1];
+    uint8_t cmsg_data[CMSG_SPACE(sizeof(struct in_addr))];
 #endif
 
     assert(fd >= 0);
@@ -518,18 +518,17 @@ int avahi_send_dns_packet_ipv4(int fd, A
 #elif defined(IP_SENDSRCADDR)
     if (src_address) {
         struct in_addr *addr;
+
+    	msg.msg_control = cmsg_data;
+    	msg.msg_controllen = sizeof(cmsg_data);
+	cmsg = CMSG_FIRSTHDR(&msg);
       
-	memset(cmsg_data, 0, sizeof(cmsg_data));
-	cmsg = (struct cmsghdr*) cmsg_data;
 	cmsg->cmsg_len = CMSG_LEN(sizeof(struct in_addr));
 	cmsg->cmsg_level = IPPROTO_IP;
 	cmsg->cmsg_type = IP_SENDSRCADDR;
 	
 	addr = (struct in_addr *)CMSG_DATA(cmsg);
 	addr->s_addr =  src_address->address;
-	
-	msg.msg_control = cmsg_data;
-	msg.msg_controllen = sizeof(cmsg_data);
     }
 #elif defined(IP_MULTICAST_IF)
     {
@@ -551,7 +550,7 @@ int avahi_send_dns_packet_ipv6(int fd, A
     struct msghdr msg;
     struct iovec io;
     struct cmsghdr *cmsg;
-    size_t cmsg_data[(CMSG_SPACE(sizeof(struct in6_pktinfo))/sizeof(size_t)) + 1];
+    uint8_t cmsg_data[CMSG_SPACE(sizeof(struct in6_pktinfo))];
 
     assert(fd >= 0);
     assert(p);
@@ -576,9 +575,11 @@ int avahi_send_dns_packet_ipv6(int fd, A
 
     if (interface > 0 || src_address) {
         struct in6_pktinfo *pkti;
+
+        msg.msg_control = cmsg_data;
+        msg.msg_controllen = sizeof(cmsg_data);
+        cmsg = CMSG_FIRSTHDR(&msg);
     
-        memset(cmsg_data, 0, sizeof(cmsg_data));
-        cmsg = (struct cmsghdr*) cmsg_data;
         cmsg->cmsg_len = CMSG_LEN(sizeof(struct in6_pktinfo));
         cmsg->cmsg_level = IPPROTO_IPV6;
         cmsg->cmsg_type = IPV6_PKTINFO;
@@ -591,8 +592,6 @@ int avahi_send_dns_packet_ipv6(int fd, A
         if (src_address)
             memcpy(&pkti->ipi6_addr, src_address->address, sizeof(src_address->address));
         
-        msg.msg_control = cmsg_data;
-        msg.msg_controllen = sizeof(cmsg_data);
     } else {
         msg.msg_control = NULL;
         msg.msg_controllen = 0;
