--- net/socket/udp_socket_posix.cc.orig	2018-01-04 21:05:56.000000000 +0100
+++ net/socket/udp_socket_posix.cc	2018-01-21 13:53:16.974899000 +0100
@@ -64,7 +64,7 @@
 const base::TimeDelta kActivityMonitorMsThreshold =
     base::TimeDelta::FromMilliseconds(100);
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Returns IPv4 address in network order.
 int GetIPv4AddressFromIndex(int socket, uint32_t index, uint32_t* address) {
@@ -617,7 +617,7 @@
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
   int value = broadcast ? 1 : 0;
   int rv;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // SO_REUSEPORT on OSX permits multiple processes to each receive
   // UDP multicast or broadcast datagrams destined for the bound
   // port.
@@ -830,7 +830,7 @@
   if (multicast_interface_ != 0) {
     switch (addr_family_) {
       case AF_INET: {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
         ip_mreqn mreq;
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
@@ -841,8 +841,20 @@
         if (error != OK)
           return error;
 #endif
+#if defined(OS_BSD)
+        int value = 1;
+        if (setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)) != 0)
+          return MapSystemError(errno);
+        if (setsockopt(socket_, SOL_SOCKET, SO_REUSEPORT, &value, sizeof(value)) != 0)
+          return MapSystemError(errno);
+#endif
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
@@ -905,7 +917,7 @@
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
       ip_mreqn mreq;
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = htonl(INADDR_ANY);
