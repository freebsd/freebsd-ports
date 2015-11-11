--- defs.pxd.orig	2015-11-01 19:57:45 UTC
+++ defs.pxd
@@ -516,7 +516,6 @@ cdef extern from "net/if_lagg.h":
         LAGG_PROTO_FAILOVER
         LAGG_PROTO_LOADBALANCE
         LAGG_PROTO_LACP
-        LAGG_PROTO_ETHERCHANNEL
 
     cdef struct lacp_opreq:
         uint16_t actor_prio
