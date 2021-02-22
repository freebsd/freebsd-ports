Upstream PR:
https://github.com/Aquantia/aqtion-freebsd/pull/11

--- aq_main.c.orig	2019-09-24 14:45:34 UTC
+++ aq_main.c
@@ -735,6 +735,23 @@ static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_co
 	}
 }
 
+#if __FreeBSD_version >= 1300054
+static u_int aq_mc_filter_apply(void *arg, struct sockaddr_dl *dl, int count)
+{
+	struct aq_dev *softc = arg;
+	struct aq_hw *hw = &softc->hw;
+	u8 *mac_addr = NULL;
+
+	if (count == AQ_HW_MAC_MAX)
+		return (0);
+
+	mac_addr = LLADDR(dl);
+	aq_hw_mac_addr_set(hw, mac_addr, count + 1);
+
+	aq_log_detail("set %d mc address %6D", count + 1, mac_addr, ":");
+	return (1);
+}
+#else
 static int aq_mc_filter_apply(void *arg, struct ifmultiaddr *ifma, int count)
 {
 	struct aq_dev *softc = arg;
@@ -752,6 +769,7 @@ static int aq_mc_filter_apply(void *arg, struct ifmult
 	aq_log_detail("set %d mc address %6D", count + 1, mac_addr, ":");
 	return (1);
 }
+#endif
 
 static bool aq_is_mc_promisc_required(struct aq_dev *softc)
 {
@@ -764,15 +782,22 @@ static void aq_if_multi_set(if_ctx_t ctx)
 	struct ifnet  *ifp = iflib_get_ifp(ctx);
 	struct aq_hw  *hw = &softc->hw;
 	AQ_DBG_ENTER();
-
+#if __FreeBSD_version >= 1300054
+	softc->mcnt = if_llmaddr_count(iflib_get_ifp(ctx));
+#else
 	softc->mcnt = if_multiaddr_count(iflib_get_ifp(ctx), AQ_HW_MAC_MAX);
+#endif
 	if (softc->mcnt >= AQ_HW_MAC_MAX)
 	{
 		aq_hw_set_promisc(hw, !!(ifp->if_flags & IFF_PROMISC),
 				  aq_is_vlan_promisc_required(softc),
 				  !!(ifp->if_flags & IFF_ALLMULTI) || aq_is_mc_promisc_required(softc));
 	}else{
+#if __FreeBSD_version >= 1300054
+		if_foreach_llmaddr(iflib_get_ifp(ctx), aq_mc_filter_apply, softc);
+#else
 		if_multi_apply(iflib_get_ifp(ctx), aq_mc_filter_apply, softc);
+#endif
 	}
 	AQ_DBG_EXIT(0);
 }
