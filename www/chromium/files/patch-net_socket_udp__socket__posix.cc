--- net/socket/udp_socket_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ net/socket/udp_socket_posix.cc
@@ -80,6 +80,10 @@
 #include "base/mac/mac_util.h"
 #endif  // BUILDFLAG(IS_MAC)
 
+#if !defined(CMSG_ALIGN)
+#define CMSG_ALIGN(n) _ALIGN(n)
+#endif
+
 namespace net {
 
 namespace {
@@ -87,7 +91,7 @@ namespace {
 constexpr int kBindRetries = 10;
 constexpr int kPortStart = 1024;
 constexpr int kPortEnd = 65535;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Maximum number of UDP packets that can be read at a time from recvmmsg.
 constexpr size_t kMaxMmsgMessages = 128;
 #endif
@@ -145,7 +149,7 @@ uint32_t GetInterfaceForDestination(const IPAddress& d
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 // Helper for IPv4 SSM. Sets sin_len on macOS, no-op on Linux.
 group_source_req CreateIPv4SourceGroupRequest(const IPAddress& group_address,
                                               const IPAddress& source_address,
@@ -277,7 +281,7 @@ int UDPSocketPosix::AdoptOpenedSocket(AddressFamily ad
   return ConfigureOpenedSocket();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 namespace {
 
 SetSocketOptionGroResult GetSetSocketOptionGroResult(int setsockopt_rv,
@@ -285,8 +289,12 @@ SetSocketOptionGroResult GetSetSocketOptionGroResult(i
   if (setsockopt_rv == 0) {
     return SetSocketOptionGroResult::kSuccess;
   }
+#if !BUILDFLAG(IS_BSD)
   if (saved_errno == ENOPROTOOPT || saved_errno == EOPNOTSUPP ||
       saved_errno == ENOPKG) {
+#else
+  if (saved_errno == ENOPROTOOPT || saved_errno == EOPNOTSUPP) {
+#endif
     return SetSocketOptionGroResult::kUnsupportedKernel;
   }
   return SetSocketOptionGroResult::kOtherError;
@@ -317,7 +325,7 @@ void RecordRecvMmsgPacketsRead(size_t packet_count) {
 #endif
 
 void UDPSocketPosix::ConfigureGroSocketOption() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   CHECK_NE(socket_, kInvalidSocket);
   CHECK_EQ(gro_status_, GroStatus::kUnconfigured);
@@ -530,7 +538,7 @@ base::expected<DatagramsMetadata, Error> UDPSocketPosi
   // when reading coalesced superpackets (e.g. UDP GRO).
   CHECK_GE(buf_len, kMinimumReadMultipleBufferSize);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (gro_status_ == GroStatus::kUnconfigured) {
     if (base::FeatureList::IsEnabled(features::kEnableUdpGro)) {
       ConfigureGroSocketOption();
@@ -829,12 +837,17 @@ int UDPSocketPosix::SetRecvTos() {
 #endif  // BUILDFLAG(IS_APPLE)
   }
 
+#ifdef IP_RECVTOS
   int rv = setsockopt(socket_, IPPROTO_IP, IP_RECVTOS, &ecn, sizeof(ecn));
+#else
+  int rv = -1;
+  errno = EOPNOTSUPP;
+#endif
   return rv == 0 ? OK : MapSystemError(errno);
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
@@ -855,7 +868,7 @@ int UDPSocketPosix::SetBroadcast(bool broadcast) {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -1138,7 +1151,7 @@ void UDPSocketPosix::FillResultFromMessageHeader(struc
       base::byte_span_from_ref(tclass_val).copy_from(cmsg_data_as_span);
       result->tos = static_cast<uint8_t>(tclass_val);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     else if (gro_status_ == GroStatus::kEnabled &&
              cmsg->cmsg_level == SOL_UDP && cmsg->cmsg_type == UDP_GRO &&
              cmsg->cmsg_len >= CMSG_LEN(sizeof(int)) &&
@@ -1171,7 +1184,7 @@ base::expected<DatagramsMetadata, Error> UDPSocketPosi
   if (socket_ == kInvalidSocket) {
     return base::unexpected(ERR_SOCKET_NOT_CONNECTED);
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (gro_status_ == GroStatus::kEnabled) {
     return InternalReadMultipleWithGro(buffer, buf_len, maximum_packet_size);
   }
@@ -1182,7 +1195,7 @@ base::expected<DatagramsMetadata, Error> UDPSocketPosi
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 base::expected<DatagramsMetadata, Error> UDPSocketPosix::InternalRecvMmsg(
     IOBuffer* buffer,
     size_t num_messages,
@@ -1554,7 +1567,7 @@ int UDPSocketPosix::DoBind(const IPEndPoint& address) 
 #if BUILDFLAG(IS_CHROMEOS)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
@@ -1654,7 +1667,7 @@ int UDPSocketPosix::LeaveGroup(const IPAddress& group_
 int UDPSocketPosix::SetSourceGroupMembership(const IPAddress& group_address,
                                              const IPAddress& source_address,
                                              int option) const {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ERR_NOT_IMPLEMENTED;
 #else
   uint32_t interface_index = multicast_interface_;
@@ -1680,6 +1693,10 @@ int UDPSocketPosix::SetSourceGroupMembership(const IPA
 #endif
 }
 
+#if !defined(MCAST_JOIN_SOURCE_GROUP)
+#define MCAST_JOIN_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::JoinSourceGroup(const IPAddress& group_address,
                                     const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
@@ -1695,6 +1712,10 @@ int UDPSocketPosix::JoinSourceGroup(const IPAddress& g
   return SetSourceGroupMembership(group_address, source_address,
                                   MCAST_JOIN_SOURCE_GROUP);
 }
+
+#if !defined(MCAST_LEAVE_SOURCE_GROUP)
+#define MCAST_LEAVE_SOURCE_GROUP 0
+#endif
 
 int UDPSocketPosix::LeaveSourceGroup(const IPAddress& group_address,
                                      const IPAddress& source_address) const {
