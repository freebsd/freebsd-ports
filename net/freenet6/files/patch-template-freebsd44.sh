--- template/freebsd44.sh.orig	Thu Nov  8 03:54:41 2001
+++ template/freebsd44.sh	Sun Feb 17 12:18:47 2002
@@ -117,7 +117,10 @@
 
    # Delete any default IPv6 route first
    ExecNoCheck $route delete -inet6 default
-   Exec $route add -inet6 default  -interface $TSP_TUNNEL_INTERFACE
+   Exec $route add -inet6 default $TSP_SERVER_ADDRESS_IPV6
+
+   # Save interface for later
+   echo $TSP_TUNNEL_INTERFACE > /var/run/tspc.if
 fi
 
 # Router configuration if required
