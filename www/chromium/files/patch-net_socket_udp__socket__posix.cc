--- net/socket/udp_socket_posix.cc.orig	2019-01-30 02:18:08.000000000 +0100
+++ net/socket/udp_socket_posix.cc	2019-02-01 23:56:02.678455000 +0100
@@ -68,7 +68,7 @@
 const base::TimeDelta kActivityMonitorMsThreshold =
     base::TimeDelta::FromMilliseconds(100);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // When enabling multicast using setsockopt(IP_MULTICAST_IF) MacOS
 // requires passing IPv4 address instead of interface index. This function
 // resolves IPv4 address by interface index. The |address| is returned in
@@ -97,7 +97,7 @@
   return OK;
 }
 
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_BSD
 
 #if defined(OS_MACOSX) && !defined(OS_IOS)
 
@@ -641,13 +641,13 @@
 }
 
 void UDPSocketPosix::SetMsgConfirm(bool confirm) {
-#if !defined(OS_MACOSX) && !defined(OS_IOS)
+#if !defined(OS_MACOSX) && !defined(OS_IOS) && !defined(OS_BSD)
   if (confirm) {
     sendto_flags_ |= MSG_CONFIRM;
   } else {
     sendto_flags_ &= ~MSG_CONFIRM;
   }
-#endif  // !defined(OS_MACOSX) && !defined(OS_IOS)
+#endif  // !defined(OS_MACOSX) && !defined(OS_IOS) && !defined(OS_BSD)
 }
 
 int UDPSocketPosix::AllowAddressReuse() {
@@ -662,17 +662,20 @@
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
   // This is only being set on OSX because its behavior is platform dependent
   // and we are playing it safe by only setting it on platforms where things
   // break.
+  rv = setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
+  if (rv != 0)
+    return MapSystemError(errno);
   rv = setsockopt(socket_, SOL_SOCKET, SO_REUSEPORT, &value, sizeof(value));
   if (rv != 0)
     return MapSystemError(errno);
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) || defined(OS_BSD)
   rv = setsockopt(socket_, SOL_SOCKET, SO_BROADCAST, &value, sizeof(value));
 
   return rv == 0 ? OK : MapSystemError(errno);
@@ -934,19 +937,24 @@
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
         ip_mreq mreq = {};
         int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
                                             &mreq.imr_interface.s_addr);
         if (error != OK)
           return error;
-#else   //  defined(OS_MACOSX)
+#else   //  defined(OS_MACOSX) || defined(OS_BSD)
         ip_mreqn mreq = {};
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
-#endif  //  !defined(OS_MACOSX)
+#endif  //  !defined(OS_MACOSX) || defined(OS_BSD)
         int rv = setsockopt(socket_, IPPROTO_IP, IP_MULTICAST_IF,
+#if defined(OS_BSD)
+                            reinterpret_cast<const char*>(&mreq.imr_interface.s_addr),
+                            sizeof(mreq.imr_interface.s_addr));
+#else
                             reinterpret_cast<const char*>(&mreq), sizeof(mreq));
+#endif
         if (rv)
           return MapSystemError(errno);
         break;
@@ -1008,7 +1016,7 @@
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
       ip_mreq mreq = {};
       int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
                                           &mreq.imr_interface.s_addr);
@@ -1056,9 +1064,18 @@
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
