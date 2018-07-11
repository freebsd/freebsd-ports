--- lib/netdev-bsd.c.orig	2018-07-11 07:15:18 UTC
+++ lib/netdev-bsd.c
@@ -65,7 +65,6 @@
 
 VLOG_DEFINE_THIS_MODULE(netdev_bsd);
 
-
 struct netdev_rxq_bsd {
     struct netdev_rxq up;
 
@@ -1511,7 +1510,7 @@ netdev_bsd_update_flags(struct netdev *netdev_, enum n
     NULL, /* get_carrier_resets */                   \
     NULL, /* set_miimon_interval */                  \
     netdev_bsd_get_stats,                            \
-                                                     \
+    NULL, /* get_custom_stats */                     \
     GET_FEATURES,                                    \
     NULL, /* set_advertisement */                    \
     NULL, /* get_pt_mode */                          \
