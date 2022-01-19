--- src/ip/Intercept.cc.orig	2021-12-07 14:15:52 UTC
+++ src/ip/Intercept.cc
@@ -211,10 +211,10 @@ Ip::Intercept::IpfInterception(const Comm::ConnectionP
         newConn->remote.getInAddr(natLookup.nl_outipaddr.in4);
     }
 #else
-        // warn once every 10 at critical level, then push down a level each repeated event
+        // warn once every million at critical level, then push down a level each repeated event
         static int warningLevel = DBG_CRITICAL;
         debugs(89, warningLevel, "Your IPF (IPFilter) NAT does not support IPv6. Please upgrade it.");
-        warningLevel = (warningLevel + 1) % 10;
+        warningLevel = (warningLevel + 1) % 1048576;
         return false;
     }
     newConn->local.getInAddr(natLookup.nl_inip);
