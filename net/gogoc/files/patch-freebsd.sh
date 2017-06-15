--- gogoc-tsp/template/freebsd.sh~	2016-07-28 01:31:15.964503000 +0800
+++ gogoc-tsp/template/freebsd.sh	2016-07-28 01:33:41.691541000 +0800
@@ -212,6 +212,7 @@
       #
       # Configured tunnel config (IPv6) 
 	
+      Exec $ifconfig $TSP_TUNNEL_INTERFACE inet6 -ifdisabled
       Exec $ifconfig $TSP_TUNNEL_INTERFACE inet6 $TSP_CLIENT_ADDRESS_IPV6 $TSP_SERVER_ADDRESS_IPV6 prefixlen $TSP_TUNNEL_PREFIXLEN alias
       Exec $ifconfig $TSP_TUNNEL_INTERFACE mtu 1280
       # 
