--- third_party/openscreen/src/platform/impl/udp_socket_posix.cc.orig	2021-04-14 18:43:06 UTC
+++ third_party/openscreen/src/platform/impl/udp_socket_posix.cc
@@ -31,7 +31,7 @@ namespace openscreen {
 namespace {
 
 // 64 KB is the maximum possible UDP datagram size.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 constexpr int kMaxUdpBufferSize = 64 << 10;
 #endif
 
@@ -381,7 +381,7 @@ bool IsPacketInfo<in6_pktinfo>(cmsghdr* cmh) {
 template <class SockAddrType, class PktInfoType>
 ErrorOr<UdpPacket> ReceiveMessageInternal(int fd) {
   int upper_bound_bytes;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // This should return the exact size of the next message.
   upper_bound_bytes = recv(fd, nullptr, 0, MSG_PEEK | MSG_TRUNC);
   if (upper_bound_bytes == -1) {
@@ -409,7 +409,7 @@ ErrorOr<UdpPacket> ReceiveMessageInternal(int fd) {
 
   // Although we don't do anything with the control buffer, on Linux
   // it is required for the message to be properly read.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   alignas(alignof(cmsghdr)) uint8_t control_buffer[1024];
   msg.msg_control = control_buffer;
   msg.msg_controllen = sizeof(control_buffer);
