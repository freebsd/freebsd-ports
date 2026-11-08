--- third_party/openscreen/src/platform/impl/udp_socket_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/openscreen/src/platform/impl/udp_socket_posix.cc
@@ -398,7 +398,7 @@ ErrorOr<UdpPacket> ReceiveMessageInternal(int fd) {
   // it's not a fatal error, we will just allocate kMaxUdpBufferSize
   // and shrink-to-fit below.
   int upper_bound_bytes = -1;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns the exact size of the datagram, or -1 on error.
   upper_bound_bytes = recv(fd, nullptr, 0, MSG_PEEK | MSG_TRUNC);
 #elif BUILDFLAG(IS_APPLE)
@@ -428,7 +428,7 @@ ErrorOr<UdpPacket> ReceiveMessageInternal(int fd) {
 
   // Although we don't do anything with the control buffer, on Linux
   // it is required for the message to be properly read.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   alignas(alignof(cmsghdr)) uint8_t control_buffer[2048];
   msg.msg_control = control_buffer;
   msg.msg_controllen = sizeof(control_buffer);
