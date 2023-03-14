--- if_re.c.orig	2023-03-12 08:31:28 UTC
+++ if_re.c
@@ -158,6 +158,10 @@ static struct re_type re_devs[] = {
                 RT_VENDORID, RT_DEVICEID_8125,
                 "Realtek PCIe 2.5GbE Family Controller"
         },
+        {
+                RT_VENDORID, RT_DEVICEID_3000,
+                "Killer PCIe 3x00 2.5GbE Family Controller"
+        },
         { 0, 0, NULL }
 };
 
@@ -2907,6 +2911,7 @@ static int re_check_mac_version(struct re_softc *sc)
         case RT_DEVICEID_8161:
         case RT_DEVICEID_8162:
         case RT_DEVICEID_8125:
+        case RT_DEVICEID_3000:
                 //do nothing
                 break;
         default:
@@ -2925,6 +2930,7 @@ static void re_init_software_variable(struct re_softc 
         case RT_DEVICEID_8162:
         case RT_DEVICEID_8136:
         case RT_DEVICEID_8125:
+        case RT_DEVICEID_3000:
                 sc->re_if_flags |= RL_FLAG_PCIE;
                 break;
         }
@@ -3846,6 +3852,7 @@ static int re_attach(device_t dev)
 
         switch(sc->re_device_id) {
         case RT_DEVICEID_8125:
+        case RT_DEVICEID_3000:
                 ifp->if_baudrate = 25000000000;
                 break;
         case RT_DEVICEID_8169:
@@ -3932,6 +3939,7 @@ static int re_attach(device_t dev)
         ifmedia_add(&sc->media, IFM_ETHER | IFM_100_TX | IFM_FDX, 0, NULL);
         switch(sc->re_device_id) {
         case RT_DEVICEID_8125:
+        case RT_DEVICEID_3000:
         case RT_DEVICEID_8169:
         case RT_DEVICEID_8169SC:
         case RT_DEVICEID_8168:
@@ -3945,6 +3953,7 @@ static int re_attach(device_t dev)
         }
         switch(sc->re_device_id) {
         case RT_DEVICEID_8125:
+        case RT_DEVICEID_3000:
                 ifmedia_add(&sc->media, IFM_ETHER | IFM_2500_T | IFM_FDX, 0, NULL);
                 break;
         default:
@@ -6362,7 +6371,7 @@ re_set_wol_linkspeed(struct re_softc *sc)
 
         if (wol_link_speed == RE_WOL_LINK_SPEED_10M_FIRST)
                 anar &= ~(ANAR_TX_FD | ANAR_TX);
-        if (sc->re_device_id==RT_DEVICEID_8125 || sc->re_device_id==RT_DEVICEID_8162) {
+        if (sc->re_device_id==RT_DEVICEID_8125 || sc->re_device_id==RT_DEVICEID_8162 || sc->re_device_id==RT_DEVICEID_3000) {
                 u_int16_t gbcr;
 
                 ClearEthPhyOcpBit(sc, 0xA5D4, RTK_ADVERTISE_2500FULL);
@@ -6607,8 +6616,8 @@ static void re_start(struct ifnet *ifp)  	/* Transmit 
                         break;
                 }
 
-                if (sc->re_type == MACFG_80 || sc->re_type == MACFG_81 ||
-                    sc->re_type == MACFG_82 || sc->re_type == MACFG_83) {
+                if (sc->re_device_id != RT_DEVICEID_3000 && (sc->re_type == MACFG_80 || sc->re_type == MACFG_81 ||
+                    sc->re_type == MACFG_82 || sc->re_type == MACFG_83)) {
                         if (re_8125_pad(sc, m_head) != 0) {
                                 IFQ_DRV_PREPEND(&ifp->if_snd, m_head);
                                 ifp->if_drv_flags |= IFF_DRV_OACTIVE;
