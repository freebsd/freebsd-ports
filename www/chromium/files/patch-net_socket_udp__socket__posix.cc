--- net/socket/udp_socket_posix.cc.orig	2021-04-14 18:41:07 UTC
+++ net/socket/udp_socket_posix.cc
@@ -72,6 +72,32 @@ const int kActivityMonitorMinimumSamplesForThroughputE
 const base::TimeDelta kActivityMonitorMsThreshold =
     base::TimeDelta::FromMilliseconds(100);
 
+#if defined(OS_BSD)
+int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
+  if (!index) {
+    *address = htonl(INADDR_ANY);
+    return OK;
+  }
+
+  sockaddr_in* result = nullptr;
+
+  ifreq ifr;
+  ifr.ifr_addr.sa_family = AF_INET;
+  if (!if_indextoname(index, ifr.ifr_name))
+    return MapSystemError(errno);
+  int rv = ioctl(socket, SIOCGIFADDR, &ifr);
+  if (rv == -1)
+    return MapSystemError(errno);
+  result = reinterpret_cast<sockaddr_in*>(&ifr.ifr_addr);
+
+  if (!result)
+    return ERR_ADDRESS_INVALID;
+
+  *address = result->sin_addr.s_addr;
+  return OK;
+}
+#endif
+
 #if defined(OS_MAC)
 
 // On OSX the file descriptor is guarded to detect the cause of
@@ -631,13 +657,13 @@ int UDPSocketPosix::SetDoNotFragment() {
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
     sendto_flags_ &= ~MSG_CONFIRM;
   }
-#endif  // !defined(OS_APPLE)
+#endif  // !defined(OS_APPLE) && !defined(OS_BSD)
 }
 
 int UDPSocketPosix::AllowAddressReuse() {
@@ -926,7 +952,11 @@ int UDPSocketPosix::SetMulticastOptions() {
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
         int rv = setsockopt(socket_, IPPROTO_IP, IP_MULTICAST_IF,
+#if defined(OS_BSD)
+                            reinterpret_cast<const char*>(&mreq.imr_address.s_addr), sizeof(mreq.imr_address.s_addr));
+#else
                             reinterpret_cast<const char*>(&mreq), sizeof(mreq));
+#endif
         if (rv)
           return MapSystemError(errno);
         break;
@@ -1027,9 +1057,18 @@ int UDPSocketPosix::LeaveGroup(const IPAddress& group_
     case IPAddress::kIPv4AddressSize: {
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
+#if defined(OS_BSD)
+      ip_mreq mreq = {};
+      int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                          &mreq.imr_interface.s_addr);
+
+      if (error != OK)
+        return error;
+#else
       ip_mreqn mreq = {};
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = INADDR_ANY;
+#endif
       memcpy(&mreq.imr_multiaddr, group_address.bytes().data(),
              IPAddress::kIPv4AddressSize);
       int rv = setsockopt(socket_, IPPROTO_IP, IP_DROP_MEMBERSHIP,
