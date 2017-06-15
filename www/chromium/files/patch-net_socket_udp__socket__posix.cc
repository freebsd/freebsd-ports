--- net/socket/udp_socket_posix.cc.orig	2017-04-19 19:06:36 UTC
+++ net/socket/udp_socket_posix.cc
@@ -59,7 +59,7 @@ const int kBindRetries = 10;
 const int kPortStart = 1024;
 const int kPortEnd = 65535;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Returns IPv4 address in network order.
 int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
@@ -765,7 +765,7 @@ int UDPSocketPosix::SetMulticastOptions(
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
         ip_mreqn mreq;
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
@@ -840,7 +840,7 @@ int UDPSocketPosix::JoinGroup(const IPAd
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       ip_mreqn mreq;
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
