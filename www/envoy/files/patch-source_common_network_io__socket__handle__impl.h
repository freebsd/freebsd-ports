--- source/common/network/io_socket_handle_impl.h.orig	2023-04-27 12:00:08 UTC
+++ source/common/network/io_socket_handle_impl.h
@@ -114,7 +114,7 @@ class IoSocketHandleImpl : public IoHandle, protected 
   // The minimum cmsg buffer size to filled in destination address, packets dropped and gso
   // size when receiving a packet. It is possible for a received packet to contain both IPv4
   // and IPV6 addresses.
-  const size_t cmsg_space_{CMSG_SPACE(sizeof(int)) + CMSG_SPACE(sizeof(struct in_pktinfo)) +
+  const size_t cmsg_space_{CMSG_SPACE(sizeof(int)) + CMSG_SPACE(sizeof(struct in_addr)) +
                            CMSG_SPACE(sizeof(struct in6_pktinfo)) + CMSG_SPACE(sizeof(uint16_t))};
 
   const bool udp_read_normalize_addresses_;
