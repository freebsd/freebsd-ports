--- netif.pyx.orig	2015-11-01 19:57:48 UTC
+++ netif.pyx
@@ -424,8 +424,6 @@ class AggregationProtocol(enum.IntEnum):
     FAILOVER = defs.LAGG_PROTO_FAILOVER
     LOADBALANCE = defs.LAGG_PROTO_LOADBALANCE
     LACP = defs.LAGG_PROTO_LACP
-    ETHERCHANNEL = defs.LAGG_PROTO_ETHERCHANNEL
-
 
 class NeighborDiscoveryFlags(enum.IntEnum):
     PERFORMNUD = defs.ND6_IFF_PERFORMNUD
