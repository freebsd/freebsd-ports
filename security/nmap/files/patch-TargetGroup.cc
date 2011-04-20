--- ./TargetGroup.cc.orig	2011-01-21 01:04:16.000000000 +0100
+++ ./TargetGroup.cc	2011-04-21 00:55:50.000000000 +0200
@@ -220,7 +220,8 @@
           resolvedaddrs.push_back(ss);
         }
       }
-      freeaddrinfo(addrs);
+      if(addrs)
+        freeaddrinfo(addrs);
 
       if (resolvedaddrs.empty()) {
         error("Failed to resolve given hostname/IP: %s.  Note that you can't use '/mask' AND '1-4,7,100-' style IP ranges", target_net);
