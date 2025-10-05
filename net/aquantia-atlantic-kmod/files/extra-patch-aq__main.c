--- aq_main.c.orig	2022-01-25 07:53:28 UTC
+++ aq_main.c
@@ -379,7 +383,7 @@ static int aq_if_attach_pre(if_ctx_t ctx)
 #else
 	if_t ifp;
 	ifp = iflib_get_ifp(ctx);
-	ifp->if_capenable =  IFCAP_RXCSUM | IFCAP_TXCSUM | IFCAP_HWCSUM | IFCAP_TSO |
+	if_setcapenable(ifp,  IFCAP_RXCSUM | IFCAP_TXCSUM | IFCAP_HWCSUM | IFCAP_TSO |
 							  IFCAP_JUMBO_MTU | IFCAP_VLAN_HWFILTER |
 							  IFCAP_VLAN_MTU | IFCAP_VLAN_HWTAGGING |
 							  IFCAP_VLAN_HWCSUM);
@@ -718,7 +722,7 @@ static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_co
 static uint64_t aq_if_get_counter(if_ctx_t ctx, ift_counter cnt)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 
 	switch (cnt) {
 	case IFCOUNTER_IERRORS:
@@ -776,7 +780,7 @@ static void aq_if_multi_set(if_ctx_t ctx)
 static void aq_if_multi_set(if_ctx_t ctx)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet  *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 	struct aq_hw  *hw = &softc->hw;
 	AQ_DBG_ENTER();
 #if __FreeBSD_version >= 1300054
@@ -786,9 +790,9 @@ static void aq_if_multi_set(if_ctx_t ctx)
 #endif
 	if (softc->mcnt >= AQ_HW_MAC_MAX)
 	{
-		aq_hw_set_promisc(hw, !!(ifp->if_flags & IFF_PROMISC),
+		aq_hw_set_promisc(hw, !!(if_getflags(ifp) & IFF_PROMISC),
 				  aq_is_vlan_promisc_required(softc),
-				  !!(ifp->if_flags & IFF_ALLMULTI) || aq_is_mc_promisc_required(softc));
+				  !!(if_getflags(ifp) & IFF_ALLMULTI) || aq_is_mc_promisc_required(softc));
 	}else{
 #if __FreeBSD_version >= 1300054
 		if_foreach_llmaddr(iflib_get_ifp(ctx), &aq_mc_filter_apply, softc);
@@ -810,7 +814,7 @@ static void aq_if_media_status(if_ctx_t ctx, struct if
 
 static void aq_if_media_status(if_ctx_t ctx, struct ifmediareq *ifmr)
 {
-	struct ifnet *ifp;
+	if_t ifp;
 
 	AQ_DBG_ENTER();
 
@@ -824,13 +828,13 @@ static int aq_if_media_change(if_ctx_t ctx)
 static int aq_if_media_change(if_ctx_t ctx)
 {
 	struct aq_dev *softc = iflib_get_softc(ctx);
-	struct ifnet *ifp = iflib_get_ifp(ctx);
+	if_t ifp = iflib_get_ifp(ctx);
 	int rc = 0;
 
 	AQ_DBG_ENTER();
 
 	/* Not allowd in UP state, since causes unsync of rings */
-	if ((ifp->if_flags & IFF_UP)){
+	if ((if_getflags(ifp) & IFF_UP)){
 		rc = EPERM;
 		goto exit;
 	}
