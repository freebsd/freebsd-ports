--- ./cop/TrafficCop.cc.orig	2013-12-05 22:07:48.000000000 +0000
+++ ./cop/TrafficCop.cc	2014-01-27 08:45:49.000000000 +0000
@@ -813,7 +813,7 @@
 
   snprintf(port_str, sizeof(port_str), "%d", port);
   memset(&hints, 0, sizeof(hints));
-  hints.ai_family = AF_UNSPEC;
+  hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
 
   err = getaddrinfo(ip, port_str, &hints, &result);
