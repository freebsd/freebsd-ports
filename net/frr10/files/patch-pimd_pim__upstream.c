Honour spt-switchover when a source is learned off the shared tree.

spt-switchover infinity-and-beyond is enforced only by withholding the register
vif from the (*,G).  That is enough while the register punt is the only way a
last hop router can learn a source, and it is not:
pim_upstream_evaluate_join_desired() joins an (S,G) as soon as its inherited
olist is non-empty and a keepalive is running, whichever tree the traffic
arrived on.  A router that learns a source another way therefore leaves the
shared tree behind the operator's back -- reproducible here, where the last hop
router holds (S,G) state so the kernel can forward at all.

Submitted upstream: https://github.com/FRRouting/frr/pull/23455

--- pimd/pim_upstream.c.orig	2026-09-24 18:59:47 UTC
+++ pimd/pim_upstream.c	2026-09-24 18:59:47 UTC
@@ -1539,6 +1539,33 @@ static inline bool pim_upstream_is_msdp_peer_sa(struct pim_upstream *up)
  *           AND inherited_olist(S,G) != NULL ) )
  *   }
  */
+/*
+ * Is this router allowed to leave the shared tree for this group?
+ *
+ * spt-switchover infinity-and-beyond says never, optionally narrowed to the
+ * groups a prefix list does not deny.  Until now the setting was enforced
+ * only by withholding the register vif from the (*,G), which is enough as
+ * long as that punt is the only way a last hop router can learn a source --
+ * it is not, so check it where the join decision is actually made.
+ */
+static bool pim_upstream_spt_switch_allowed(struct pim_instance *pim, pim_addr grp)
+{
+	struct prefix_list *plist;
+	struct prefix g;
+
+	if (pim->spt.switchover != PIM_SPT_INFINITY)
+		return true;
+
+	if (!pim->spt.plist)
+		return false;
+
+	plist = prefix_list_lookup(PIM_AFI, pim->spt.plist);
+	pim_addr_to_prefix(&g, grp);
+
+	/* A group the list denies is exempt from the never-switch policy. */
+	return prefix_list_apply_ext(plist, NULL, &g, true) == PREFIX_DENY;
+}
+
 bool pim_upstream_evaluate_join_desired(struct pim_instance *pim,
 				       struct pim_upstream *up)
 {
@@ -1556,9 +1583,19 @@ bool pim_upstream_evaluate_join_desired(struct pim_instance *pim,
 		return true;
 	empty_inh_oil = pim_upstream_empty_inherited_olist(up);
 	if (!empty_inh_oil &&
-			(pim_upstream_is_kat_running(up) ||
-			 pim_upstream_is_msdp_peer_sa(up)))
+	    (pim_upstream_is_kat_running(up) || pim_upstream_is_msdp_peer_sa(up))) {
+		/*
+		 * Joining an (S,G) whose traffic is arriving on the shared
+		 * tree is the last-hop switch to the source tree.  Where the
+		 * operator has turned that off, stay on the shared tree
+		 * however much traffic shows up.
+		 */
+		if (PIM_UPSTREAM_FLAG_TEST_USE_RPT(up->flags) &&
+		    !pim_upstream_spt_switch_allowed(pim, up->sg.grp))
+			return false;
+
 		return true;
+	}
 
 	return false;
 }
