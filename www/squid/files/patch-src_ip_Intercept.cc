--- src/ip/Intercept.cc.orig	2024-03-04 05:45:51 UTC
+++ src/ip/Intercept.cc
@@ -218,10 +218,10 @@ Ip::Intercept::IpfInterception(const Comm::ConnectionP
         newConn->remote.getInAddr(natLookup.nl_outipaddr.in4);
     }
 #else /* HAVE_STRUCT_NATLOOKUP_NL_INIPADDR_IN6 */
-        // warn once every 10 at critical level, then push down a level each repeated event
+        // warn once every million at critical level, then push down a level each repeated event
         static int warningLevel = DBG_CRITICAL;
         debugs(89, warningLevel, "Your IPF (IPFilter) NAT does not support IPv6. Please upgrade it.");
-        warningLevel = (warningLevel + 1) % 10;
+        warningLevel = (warningLevel + 1) % 1048576;
         return false;
     }
     newConn->local.getInAddr(natLookup.nl_inip);
