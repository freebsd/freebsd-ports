--- src/ip/Intercept.cc.orig	2016-12-16 10:06:20 UTC
+++ src/ip/Intercept.cc
@@ -206,10 +206,10 @@ Ip::Intercept::IpfInterception(const Com
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
     }
     newConn->local.getInAddr(natLookup.nl_inip);
