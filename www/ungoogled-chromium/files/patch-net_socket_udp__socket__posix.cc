--- net/socket/udp_socket_posix.cc.orig	2026-04-15 11:25:12 UTC
+++ net/socket/udp_socket_posix.cc
@@ -135,7 +135,7 @@ uint32_t GetInterfaceForDestination(const IPAddress& d
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
 // Helper for IPv4 SSM. Sets sin_len on macOS, no-op on Linux.
 group_source_req CreateIPv4SourceGroupRequest(const IPAddress& group_address,
                                               const IPAddress& source_address,
@@ -674,12 +674,17 @@ int UDPSocketPosix::SetRecvTos() {
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
@@ -700,7 +705,7 @@ int UDPSocketPosix::SetBroadcast(bool broadcast) {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -1074,7 +1079,7 @@ int UDPSocketPosix::DoBind(const IPEndPoint& address) 
 #if BUILDFLAG(IS_CHROMEOS)
   if (last_error == EINVAL)
     return ERR_ADDRESS_IN_USE;
-#elif BUILDFLAG(IS_APPLE)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   if (last_error == EADDRNOTAVAIL)
     return ERR_ADDRESS_IN_USE;
 #endif
@@ -1174,7 +1179,7 @@ int UDPSocketPosix::LeaveGroup(const IPAddress& group_
 int UDPSocketPosix::SetSourceGroupMembership(const IPAddress& group_address,
                                              const IPAddress& source_address,
                                              int option) const {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ERR_NOT_IMPLEMENTED;
 #else
   uint32_t interface_index = multicast_interface_;
@@ -1200,6 +1205,10 @@ int UDPSocketPosix::SetSourceGroupMembership(const IPA
 #endif
 }
 
+#if !defined(MCAST_JOIN_SOURCE_GROUP)
+#define MCAST_JOIN_SOURCE_GROUP 0
+#endif
+
 int UDPSocketPosix::JoinSourceGroup(const IPAddress& group_address,
                                     const IPAddress& source_address) const {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
@@ -1215,6 +1224,10 @@ int UDPSocketPosix::JoinSourceGroup(const IPAddress& g
   return SetSourceGroupMembership(group_address, source_address,
                                   MCAST_JOIN_SOURCE_GROUP);
 }
+
+#if !defined(MCAST_LEAVE_SOURCE_GROUP)
+#define MCAST_LEAVE_SOURCE_GROUP 0
+#endif
 
 int UDPSocketPosix::LeaveSourceGroup(const IPAddress& group_address,
                                      const IPAddress& source_address) const {
