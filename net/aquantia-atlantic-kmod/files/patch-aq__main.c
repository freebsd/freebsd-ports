Upstream PR:
https://github.com/Aquantia/aqtion-freebsd/pull/11

--- aq_main.c.orig	2019-09-24 14:45:34 UTC
+++ aq_main.c
@@ -193,8 +193,12 @@ static driver_t aq_driver = {
 	"aq", aq_methods, sizeof(struct aq_dev),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(atlantic, pci, aq_driver, 0, 0);
+#else
 static devclass_t aq_devclass;
 DRIVER_MODULE(atlantic, pci, aq_driver, aq_devclass, 0, 0);
+#endif
 
 MODULE_DEPEND(atlantic, pci, 1, 1, 1);
 MODULE_DEPEND(atlantic, ether, 1, 1, 1);
@@ -282,8 +286,6 @@ static struct if_shared_ctx aq_sctx_init = {
 	.isc_ntxd_default = {PAGE_SIZE / sizeof(aq_txc_desc_t) * 4},
 };
 
-if_shared_ctx_t aq_sctx = &aq_sctx_init;
-
 /*
  * TUNEABLE PARAMETERS:
  */
@@ -300,7 +302,7 @@ static void *aq_register(device_t dev)
  */
 static void *aq_register(device_t dev)
 {
-	return (aq_sctx);
+	return (&aq_sctx_init);
 }
 
 static int aq_if_attach_pre(if_ctx_t ctx)
@@ -417,13 +419,11 @@ static int aq_if_attach_post(if_ctx_t ctx)
 static int aq_if_attach_post(if_ctx_t ctx)
 {
 	struct aq_dev *softc;
-	if_t ifp;
 	int rc;
 
 	AQ_DBG_ENTER();
 
 	softc = iflib_get_softc(ctx);
-	ifp = iflib_get_ifp(ctx);
 	rc = 0;
 
 	aq_update_hw_stats(softc);
@@ -635,13 +635,11 @@ static void aq_if_init(if_ctx_t ctx)
 	struct aq_dev *softc;
 	struct aq_hw *hw;
 	struct ifmediareq ifmr;
-	struct ifnet *ifp;
 	int i, err;
 
 	AQ_DBG_ENTER();
 	softc = iflib_get_softc(ctx);
 	hw = &softc->hw;
-	ifp = iflib_get_ifp(ctx);
 
 	err = aq_hw_init(&softc->hw, softc->hw.mac_addr, softc->msix,
 					softc->scctx->isc_intr == IFLIB_INTR_MSIX);
@@ -735,6 +733,23 @@ static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_co
 	}
 }
 
+#if __FreeBSD_version >= 1300054
+static u_int aq_mc_filter_apply(void *arg, struct sockaddr_dl *dl, u_int count)
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
+	aq_log_detail("set %u mc address %6D", count + 1, mac_addr, ":");
+	return (1);
+}
+#else
 static int aq_mc_filter_apply(void *arg, struct ifmultiaddr *ifma, int count)
 {
 	struct aq_dev *softc = arg;
@@ -752,6 +767,7 @@ static int aq_mc_filter_apply(void *arg, struct ifmult
 	aq_log_detail("set %d mc address %6D", count + 1, mac_addr, ":");
 	return (1);
 }
+#endif
 
 static bool aq_is_mc_promisc_required(struct aq_dev *softc)
 {
@@ -764,15 +780,22 @@ static void aq_if_multi_set(if_ctx_t ctx)
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
@@ -825,12 +848,10 @@ static int aq_if_promisc_set(if_ctx_t ctx, int flags)
 static int aq_if_promisc_set(if_ctx_t ctx, int flags)
 {
 	struct aq_dev *softc;
-	struct ifnet *ifp;
 
 	AQ_DBG_ENTER();
 
 	softc = iflib_get_softc(ctx);
-	ifp = iflib_get_ifp(softc->ctx);
 
 	aq_hw_set_promisc(&softc->hw, !!(flags & IFF_PROMISC),
 			  aq_is_vlan_promisc_required(softc),
