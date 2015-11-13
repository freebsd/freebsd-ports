--- mDNSPosix/mDNSPosix.c.orig	2015-03-13 00:15:32 UTC
+++ mDNSPosix/mDNSPosix.c
@@ -516,6 +516,7 @@ mDNSexport int ParseDNSServers(mDNS *m, 
             numOfServers++;
         }
     }
+    fclose(fp);
     return (numOfServers > 0) ? 0 : -1;
 }
 
@@ -740,7 +741,13 @@ mDNSlocal int SetupSocket(struct sockadd
     {
         struct ipv6_mreq imr6;
         struct sockaddr_in6 bindAddr6;
-    #if defined(IPV6_PKTINFO)
+    #if defined(IPV6_RECVPKTINFO)
+        if (err == 0)
+        {
+            err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_RECVPKTINFO, &kOn, sizeof(kOn));
+            if (err < 0) { err = errno; perror("setsockopt - IPV6_RECVPKTINFO"); }
+        }
+    #elif defined(IPV6_PKTINFO)
         if (err == 0)
         {
             err = setsockopt(*sktPtr, IPPROTO_IPV6, IPV6_2292_PKTINFO, &kOn, sizeof(kOn));
@@ -749,7 +756,13 @@ mDNSlocal int SetupSocket(struct sockadd
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
@@ -1600,7 +1613,7 @@ mDNSexport mDNSs32 mDNSPlatformGetServic
     return -1;
 }
 
-mDNSexport void mDNSPlatformSetDelegatePID(UDPSocket *src, const mDNSAddr *dst, DNSQuestion *q)
+mDNSexport void mDNSPlatformSetuDNSSocktOpt(UDPSocket *src, const mDNSAddr *dst, DNSQuestion *q)
 {
     (void) src;
     (void) dst;
