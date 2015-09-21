--- src/ip/Intercept.cc.orig	2015-09-01 12:52:00.000000000 -0700
+++ src/ip/Intercept.cc	2015-09-17 21:52:44.892553613 -0700
@@ -202,10 +202,10 @@
     // for NAT lookup set local and remote IP:port's
     if (newConn->remote.isIPv6()) {
 #if IPFILTER_VERSION < 5000003
-        // warn once every 10 at critical level, then push down a level each repeated event
+        // warn once every million at critical level, then push down a level each repeated event
         static int warningLevel = DBG_CRITICAL;
         debugs(89, warningLevel, "IPF (IPFilter v4) NAT does not support IPv6. Please upgrade to IPFilter v5.1");
-        warningLevel = ++warningLevel % 10;
+        warningLevel = (warningLevel + 1) % 1048576;
         return false;
 #else
         natLookup.nl_v = 6;
