--- lib/zclient.h.orig	2018-07-12 06:57:20 UTC
+++ lib/zclient.h
@@ -353,10 +353,6 @@ struct zclient_options {
 /* Prototypes of zebra client service functions. */
 extern struct zclient *zclient_new(struct thread_master *);
 
-#if CONFDATE > 20181101
-CPP_NOTICE("zclient_new_notify can take over or zclient_new now");
-#endif
-
 extern struct zclient_options zclient_options_default;
 
 extern struct zclient *zclient_new_notify(struct thread_master *m,
@@ -421,10 +417,6 @@ extern struct interface *zebra_interface_vrf_update_re
 							 vrf_id_t *new_vrf_id);
 extern void zebra_interface_if_set_value(struct stream *, struct interface *);
 extern void zebra_router_id_update_read(struct stream *s, struct prefix *rid);
-
-#if CONFDATE > 20180823
-CPP_NOTICE("zapi_ipv4_route, zapi_ipv6_route, zapi_ipv4_route_ipv6_nexthop as well as the zapi_ipv4 and zapi_ipv6 data structures should be removed now");
-#endif
 
 extern int zapi_ipv4_route(u_char, struct zclient *, struct prefix_ipv4 *,
 			   struct zapi_ipv4 *) __attribute__((deprecated));
