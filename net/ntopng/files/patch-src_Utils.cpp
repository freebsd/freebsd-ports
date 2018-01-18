--- src/Utils.cpp.orig	2018-01-12 09:48:20 UTC
+++ src/Utils.cpp
@@ -2370,7 +2370,7 @@ int Utils::bindSockToDevice(int sock, int family, cons
 
   if(pAdapterFound != NULL) {
     int addrsize = (family == AF_INET6) ? sizeof(sockaddr_in6) : sizeof(sockaddr_in);
-    bindresult = bind(sock, pAdapterFound->ifa_addr, addrsize);
+    bindresult = ::bind(sock, pAdapterFound->ifa_addr, addrsize);
   }
 
   freeifaddrs(pList);
