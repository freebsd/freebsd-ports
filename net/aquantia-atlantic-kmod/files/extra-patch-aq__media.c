--- aq_media.c.orig	2022-01-25 07:53:28 UTC
+++ aq_media.c
@@ -94,9 +94,9 @@ void aq_mediastatus_update(aq_dev_t *aq_dev, u32 link_
 		aq_dev->media_active |= IFM_AUTO;
 }
 
-void aq_mediastatus(struct ifnet *ifp, struct ifmediareq *ifmr)
+void aq_mediastatus(if_t ifp, struct ifmediareq *ifmr)
 {
-	aq_dev_t *aq_dev = iflib_get_softc(ifp->if_softc);
+	aq_dev_t *aq_dev = iflib_get_softc(if_getsoftc(ifp));
 
 	ifmr->ifm_active = IFM_ETHER;
 	ifmr->ifm_status = IFM_AVALID;
@@ -107,11 +107,11 @@ void aq_mediastatus(struct ifnet *ifp, struct ifmediar
 	ifmr->ifm_active |= aq_dev->media_active;
 }
 
-int aq_mediachange(struct ifnet *ifp)
+int aq_mediachange(if_t ifp)
 {
-	aq_dev_t          *aq_dev = iflib_get_softc(ifp->if_softc);
+	aq_dev_t          *aq_dev = iflib_get_softc(if_getsoftc(ifp));
 	struct aq_hw      *hw = &aq_dev->hw;
-	int                old_media_rate = ifp->if_baudrate;
+	int                old_media_rate = if_getbaudrate(ifp);
 	int                old_link_speed = hw->link_rate;
 	struct ifmedia    *ifm = iflib_get_media(aq_dev->ctx);
 	int                user_media = IFM_SUBTYPE(ifm->ifm_media);
@@ -169,7 +169,7 @@ int aq_mediachange(struct ifnet *ifp)
 	hw->fc.fc_tx = (ifm->ifm_media & IFM_ETH_TXPAUSE) ? 1 : 0;
 
 	/* In down state just remember new link speed */
-	if (!(ifp->if_flags & IFF_UP))
+	if (!(if_getflags(ifp) & IFF_UP))
 		return (0);
 
 	if ((media_rate != old_media_rate) || (hw->link_rate != old_link_speed)) {
