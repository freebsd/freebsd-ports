--- template/freebsd4.sh.orig	Thu Oct 11 16:40:29 2001
+++ template/freebsd4.sh	Thu Oct 11 16:40:48 2001
@@ -92,7 +92,7 @@
 fi
 
 #change to upper case
-TSP_HOST_TYPE=`echo $TSP_HOST_TYPE | tr a-z A-Z`
+TSP_HOST_TYPE=`echo $TSP_HOST_TYPE | tr [:lower:] [:upper:]`

 if [ X"${TSP_HOST_TYPE}" = X"HOST" ] || [ X"${TSP_HOST_TYPE}" = X"ROUTER" ]; then
    #
@@ -122,6 +122,9 @@
    # Delete any default IPv6 route first
    ExecNoCheck $route delete -inet6 default
    Exec $route add -inet6 default  -interface $TSP_TUNNEL_INTERFACE
+
+   # Save interface for later
+   echo $TSP_TUNNEL_INTERFACE > /var/run/tspc.if
 fi
 
 # Router configuration if required
