--- bgpd/bgp_nht.c.orig	2017-10-03 16:57:10.000000000 +0200
+++ bgpd/bgp_nht.c	2017-12-15 21:12:37.058505000 +0100
@@ -409,8 +409,8 @@
       break;
 #ifdef HAVE_IPV6
     case AFI_IP6:
-      if (ri->attr->extra->mp_nexthop_len != 16
-	  || IN6_IS_ADDR_LINKLOCAL (&ri->attr->extra->mp_nexthop_global))
+      if (ri->attr->extra->mp_nexthop_len == 16
+	  && IN6_IS_ADDR_LINKLOCAL (&ri->attr->extra->mp_nexthop_global))
 	return -1;
 
       p->family = AF_INET6;
