--- mDNSPosix/mDNSPosix.c.orig	2012-04-18 07:01:01.000000000 +0800
+++ mDNSPosix/mDNSPosix.c	2013-08-16 23:04:31.089791517 +0800
@@ -503,6 +503,7 @@
             numOfServers++;
         }
     }
+    fclose(fp);
     return (numOfServers > 0) ? 0 : -1;
 }
 
@@ -708,7 +709,13 @@
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
@@ -717,7 +724,13 @@
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
