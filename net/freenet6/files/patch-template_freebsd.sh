--- template/freebsd.sh.orig	2017-06-16 09:11:57 UTC
+++ template/freebsd.sh
@@ -201,7 +201,7 @@ if [ X"${TSP_TUNNEL_MODE}" = X"v6v4" ] || [ X"${TSP_TU
       fi
       #
       # Configured tunnel config (IPv6) 
-	
+      Exec $ifconfig $TSP_TUNNEL_INTERFACE inet6 -ifdisabled
       Exec $ifconfig $TSP_TUNNEL_INTERFACE inet6 $TSP_CLIENT_ADDRESS_IPV6 $TSP_SERVER_ADDRESS_IPV6 prefixlen $TSP_TUNNEL_PREFIXLEN alias
       Exec $ifconfig $TSP_TUNNEL_INTERFACE mtu 1280
       # 
