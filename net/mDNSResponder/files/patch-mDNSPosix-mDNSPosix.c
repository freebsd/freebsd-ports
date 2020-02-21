--- mDNSPosix/mDNSPosix.c.orig	2019-06-27 09:29:40 UTC
+++ mDNSPosix/mDNSPosix.c
@@ -971,7 +971,7 @@ mDNSlocal int SetupSocket(struct sockaddr *intfAddr, m
         // to bind to the socket. Our suggestion was to switch the order in which
         // SO_REUSEPORT and SO_REUSEADDR was tested so that SO_REUSEADDR stays on
         // top and SO_REUSEPORT to be used only if SO_REUSEADDR doesn't exist.
-        #if defined(SO_REUSEADDR) && !defined(__MAC_OS_X_VERSION_MIN_REQUIRED)
+        #if defined(SO_REUSEADDR) && !defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && !defined(__FreeBSD__)
         err = setsockopt(*sktPtr, SOL_SOCKET, SO_REUSEADDR, &kOn, sizeof(kOn));
         #elif defined(SO_REUSEPORT)
         err = setsockopt(*sktPtr, SOL_SOCKET, SO_REUSEPORT, &kOn, sizeof(kOn));
@@ -1074,16 +1074,28 @@ mDNSlocal int SetupSocket(struct sockaddr *intfAddr, m
     {
         struct ipv6_mreq imr6;
         struct sockaddr_in6 bindAddr6;
-    #if defined(IPV6_PKTINFO)
+    #if defined(IPV6_RECVPKTINFO)
         if (err == 0)
         {
+            err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_RECVPKTINFO, &kOn, sizeof(kOn));
+            if (err < 0) { err = errno; perror("setsockopt - IPV6_RECVPKTINFO"); }
+        }
+    #elif defined(IPV6_PKTINFO)
+        if (err == 0)
+        {
             err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_2292_PKTINFO, &kOn, sizeof(kOn));
             if (err < 0) { err = errno; perror("setsockopt - IPV6_PKTINFO"); }
         }
     #else
         #warning This platform has no way to get the destination interface information for IPv6 -- will only work for single-homed hosts
     #endif
-    #if defined(IPV6_HOPLIMIT)
+    #if defined(IPV6_RECVHOPLIMIT)
+        if (err == 0)
+        {
+            err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_RECVHOPLIMIT, &kOn, sizeof(kOn));
+            if (err < 0) { err = errno; perror("setsockopt - IPV6_RECVHOPLIMIT"); }
+        }
+    #elif defined(IPV6_HOPLIMIT)
         if (err == 0)
         {
             err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_2292_HOPLIMIT, &kOn, sizeof(kOn));
