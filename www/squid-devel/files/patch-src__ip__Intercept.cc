--- src/ip/Intercept.cc.orig	2015-11-01 10:44:25 UTC
+++ src/ip/Intercept.cc
@@ -202,10 +202,10 @@ Ip::Intercept::IpfInterception(const Com
     // for NAT lookup set local and remote IP:port's
     if (newConn->remote.isIPv6()) {
 #if IPFILTER_VERSION < 5000003
-        // warn once every 10 at critical level, then push down a level each repeated event
+        // warn once every million at critical level, then push down a level each repeated event
         static int warningLevel = DBG_CRITICAL;
         debugs(89, warningLevel, "IPF (IPFilter v4) NAT does not support IPv6. Please upgrade to IPFilter v5.1");
-        warningLevel = (warningLevel + 1) % 10;
+        warningLevel = (warningLevel + 1) % 1048576;
         return false;
 #else
         natLookup.nl_v = 6;
@@ -323,13 +323,21 @@
     }
 
     memset(&nl, 0, sizeof(struct pfioc_natlook));
-    newConn->remote.getInAddr(nl.saddr.v4);
+    if (newConn->remote.isIPv4()) {
+        newConn->remote.getInAddr(nl.saddr.v4);
+    } else {
+        newConn->remote.getInAddr(nl.saddr.v6);
+    }
     nl.sport = htons(newConn->remote.port());
 
-    newConn->local.getInAddr(nl.daddr.v4);
+    if (newConn->local.isIPv4()) {
+        newConn->local.getInAddr(nl.daddr.v4);
+    } else {
+        newConn->local.getInAddr(nl.daddr.v6);
+    }
     nl.dport = htons(newConn->local.port());
 
-    nl.af = AF_INET;
+    nl.af = newConn->remote.isIPv4() ? AF_INET : AF_INET6;
     nl.proto = IPPROTO_TCP;
     nl.direction = PF_OUT;
 
@@ -345,7 +353,11 @@
         debugs(89, 9, HERE << "address: " << newConn);
         return false;
     } else {
-        newConn->local = nl.rdaddr.v4;
+        if (nl.af == AF_INET) {
+            newConn->local = nl.rdaddr.v4;
+        } else {
+            newConn->local = nl.rdaddr.v6;
+        }
         newConn->local.port(ntohs(nl.rdport));
         debugs(89, 5, HERE << "address NAT: " << newConn);
         return true;
