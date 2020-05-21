--- bgpd/bgp_routemap.c.orig	2019-01-08 08:29:22 UTC
+++ bgpd/bgp_routemap.c
@@ -2452,11 +2452,11 @@ route_set_ipv6_nexthop_prefer_global(void *rule, const
 		    && peer->su_remote
 		    && sockunion_family(peer->su_remote) == AF_INET6) {
 			/* Set next hop preference to global */
-			bgp_info->attr->mp_nexthop_prefer_global = TRUE;
+			bgp_info->attr->mp_nexthop_prefer_global = true;
 			SET_FLAG(bgp_info->attr->rmap_change_flags,
 				 BATTR_RMAP_IPV6_PREFER_GLOBAL_CHANGED);
 		} else {
-			bgp_info->attr->mp_nexthop_prefer_global = FALSE;
+			bgp_info->attr->mp_nexthop_prefer_global = false;
 			SET_FLAG(bgp_info->attr->rmap_change_flags,
 				 BATTR_RMAP_IPV6_PREFER_GLOBAL_CHANGED);
 		}
