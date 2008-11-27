--- ospfd/rde_spf.c	2007/08/06 11:32:34	1.63
+++ ospfd/rde_spf.c	2007/09/16 15:00:11	1.64
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_spf.c,v 1.63 2007/08/06 11:32:34 claudio Exp $ */
+/*	$OpenBSD: rde_spf.c,v 1.64 2007/09/16 15:00:11 claudio Exp $ */
 
 /*
  * Copyright (c) 2005 Esben Norby <norby@openbsd.org>
@@ -37,7 +37,8 @@
 
 void		 calc_nexthop_clear(struct vertex *);
 void		 calc_nexthop_add(struct vertex *, struct vertex *, u_int32_t);
-void		 calc_nexthop(struct vertex *, struct vertex *);
+void		 calc_nexthop(struct vertex *, struct vertex *,
+		     struct area *, struct lsa_rtr_link *);
 void		 rt_nexthop_clear(struct rt_node *);
 void		 rt_nexthop_add(struct rt_node *, struct v_nexthead *,
 		     struct in_addr);
@@ -134,7 +135,7 @@
 				if (d < w->cost) {
 					w->cost = d;
 					calc_nexthop_clear(w);
-					calc_nexthop(w, v);
+					calc_nexthop(w, v, area, rtr_link);
 					/*
 					 * need to readd to candidate list
 					 * because the list is sorted
@@ -143,12 +144,12 @@
 					cand_list_add(w);
 				} else
 					/* equal cost path */
-					calc_nexthop(w, v);
+					calc_nexthop(w, v, area, rtr_link);
 			} else if (w->cost == LS_INFINITY && d < LS_INFINITY) {
 				w->cost = d;
 
 				calc_nexthop_clear(w);
-				calc_nexthop(w, v);
+				calc_nexthop(w, v, area, rtr_link);
 				cand_list_add(w);
 			}
 		}
@@ -384,54 +385,51 @@
 }
 
 void
-calc_nexthop(struct vertex *dst, struct vertex *parent)
+calc_nexthop(struct vertex *dst, struct vertex *parent,
+    struct area *area, struct lsa_rtr_link *rtr_link)
 {
-	struct lsa_rtr_link	*rtr_link = NULL;
 	struct v_nexthop	*vn;
+	struct iface		*iface;
 	int			 i;
 
 	/* case 1 */
 	if (parent == spf_root) {
 		switch (dst->type) {
 		case LSA_TYPE_ROUTER:
-			for (i = 0; i < lsa_num_links(dst); i++) {
-				rtr_link = get_rtr_link(dst, i);
-				if (rtr_link->type == LINK_TYPE_POINTTOPOINT &&
-				    ntohl(rtr_link->id) == parent->ls_id) {
+			if (rtr_link->type != LINK_TYPE_POINTTOPOINT)
+				fatalx("inconsistent SPF tree");
+			LIST_FOREACH(iface, &area->iface_list, entry) {
+				if (rtr_link->data == iface->addr.s_addr) {
 					calc_nexthop_add(dst, parent,
-					    rtr_link->data);
-					break;
+					    iface->dst.s_addr);
+					return;
 				}
 			}
-			return;
+			fatalx("no interface found for interface");
 		case LSA_TYPE_NETWORK:
-			for (i = 0; i < lsa_num_links(parent); i++) {
-				rtr_link = get_rtr_link(parent, i);
-				switch (rtr_link->type) {
-				case LINK_TYPE_POINTTOPOINT:
-					/* ignore */
-					break;
-				case LINK_TYPE_TRANSIT_NET:
-					if ((htonl(dst->ls_id) &
-					    dst->lsa->data.net.mask) ==
-					    (rtr_link->data &
-					     dst->lsa->data.net.mask)) {
-						calc_nexthop_add(dst, parent,
-						    rtr_link->data);
-					}
-					break;
-				case LINK_TYPE_STUB_NET:
-					break;
-
-				default:
-					fatalx("calc_nexthop: invalid link "
-					    "type");
+			switch (rtr_link->type) {
+			case LINK_TYPE_POINTTOPOINT:
+			case LINK_TYPE_STUB_NET:
+				/* ignore */
+				break;
+			case LINK_TYPE_TRANSIT_NET:
+				if ((htonl(dst->ls_id) &
+				    dst->lsa->data.net.mask) ==
+				    (rtr_link->data &
+				     dst->lsa->data.net.mask)) {
+					calc_nexthop_add(dst, parent,
+					    rtr_link->data);
 				}
+				break;
+			default:
+				fatalx("calc_nexthop: invalid link "
+				    "type");
 			}
 			return;
 		default:
 			fatalx("calc_nexthop: invalid dst type");
 		}
+		return;
 	}
 
 	/* case 2 */
@@ -459,7 +457,7 @@
 
 	/* case 3 */
 	TAILQ_FOREACH(vn, &parent->nexthop, entry)
-	    calc_nexthop_add(dst, parent, vn->nexthop.s_addr);
+		calc_nexthop_add(dst, parent, vn->nexthop.s_addr);
 }
 
 /* candidate list */
