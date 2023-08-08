--- mDNSPosix/mDNSPosix.c.orig	2023-01-24 00:43:17 UTC
+++ mDNSPosix/mDNSPosix.c
@@ -1064,7 +1064,10 @@ mDNSlocal int SetupIPv6Socket(int fd)
 {
     int err;
 
-    #if defined(IPV6_PKTINFO)
+    #if defined(IPV6_RECVPKTINFO)
+    err = setsockopt(fd, IPPROTO_IPV6, IPV6_RECVPKTINFO, &kOn, sizeof(kOn));
+    if (err < 0) { err = errno; perror("setsockopt - IPV6_RECVPKTINFO"); }
+    #elif defined(IPV6_PKTINFO)
     err = setsockopt(fd, IPPROTO_IPV6, IPV6_2292_PKTINFO, &kOn, sizeof(kOn));
     if (err < 0) { err = errno; perror("setsockopt - IPV6_PKTINFO"); }
     #else
@@ -1135,7 +1138,7 @@ mDNSlocal int SetupSocket(struct sockaddr *intfAddr, m
         // to bind to the socket. Our suggestion was to switch the order in which
         // SO_REUSEPORT and SO_REUSEADDR was tested so that SO_REUSEADDR stays on
         // top and SO_REUSEPORT to be used only if SO_REUSEADDR doesn't exist.
-        #if defined(SO_REUSEADDR) && !defined(__MAC_OS_X_VERSION_MIN_REQUIRED)
+        #if defined(SO_REUSEADDR) && !defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && !defined(__FreeBSD__)
         err = setsockopt(*sktPtr, SOL_SOCKET, SO_REUSEADDR, &kOn, sizeof(kOn));
         #elif defined(SO_REUSEPORT)
         err = setsockopt(*sktPtr, SOL_SOCKET, SO_REUSEPORT, &kOn, sizeof(kOn));
@@ -1224,7 +1227,13 @@ mDNSlocal int SetupSocket(struct sockaddr *intfAddr, m
         if (err == 0) {
             err = SetupIPv6Socket(*sktPtr);
         }
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
