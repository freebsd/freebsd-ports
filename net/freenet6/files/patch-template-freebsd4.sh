--- template/freebsd4.sh.orig	Thu Oct 11 16:40:29 2001
+++ template/freebsd4.sh	Thu Oct 11 16:40:48 2001
@@ -110,6 +110,9 @@
    # Delete any default IPv6 route first
    Exec $route delete -inet6 default
    Exec $route add -inet6 default  -interface $TSP_TUNNEL_INTERFACE
+
+   # Save interface for later
+   echo $TSP_TUNNEL_INTERFACE > /var/run/tspc.if
 fi
 
 # Router configuration if required
