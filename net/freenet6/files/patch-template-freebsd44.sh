--- template/freebsd44.sh.orig	Tue Aug 28 04:15:58 2001
+++ template/freebsd44.sh	Thu Oct 11 15:22:00 2001
@@ -106,6 +106,9 @@
    # Delete any default IPv6 route first
    Exec $route delete -inet6 default
    Exec $route add -inet6 default  -interface $TSP_TUNNEL_INTERFACE
+
+   # Save interface for later
+   echo $TSP_TUNNEL_INTERFACE > /var/run/tspc.if
 fi
 
 # Router configuration if required
