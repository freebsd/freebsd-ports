--- template/freebsd44.sh.orig	Sat Feb 23 06:32:37 2002
+++ template/freebsd44.sh	Sat Mar  2 09:53:54 2002
@@ -118,6 +118,9 @@
    # Delete any default IPv6 route first
    ExecNoCheck $route delete -inet6 default
    Exec $route add -inet6 default $TSP_SERVER_ADDRESS_IPV6
+
+   # Save interface for later
+   echo $TSP_TUNNEL_INTERFACE > /var/run/tspc.if
 fi
 
 # Router configuration if required
