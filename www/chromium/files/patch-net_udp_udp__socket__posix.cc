--- net/udp/udp_socket_posix.cc.orig	2016-12-16 03:54:19.436860000 +0000
+++ net/udp/udp_socket_posix.cc	2016-12-16 03:55:18.231119000 +0000
@@ -51,7 +51,7 @@
 const int kPortStart = 1024;
 const int kPortEnd = 65535;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Returns IPv4 address in network order.
 int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
@@ -679,7 +679,7 @@
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
         ip_mreqn mreq;
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
@@ -754,7 +754,7 @@
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       ip_mreqn mreq;
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
