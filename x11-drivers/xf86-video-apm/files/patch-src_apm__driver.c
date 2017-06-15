# Remove miInitializeBackingStore; it no longer exists and
# should have been removed with the mibstore.h include
#
# Replace xf86UnMapVidMem with pci_device_unmap_range
#
# Correct one string that should be const
#
--- src/apm_driver.c.orig	2012-07-17 04:52:01 UTC
+++ src/apm_driver.c
@@ -355,7 +355,8 @@ ApmPreInit(ScrnInfoPtr pScrn, int flags)
     EntityInfoPtr	pEnt;
     vgaHWPtr		hwp;
     MessageType		from;
-    char		*mod = NULL, *req = NULL, *s;
+    char		*mod = NULL, *req = NULL;
+    const char		*s;
     ClockRangePtr	clockRanges;
     int			i;
     xf86MonPtr		MonInfo = NULL;
@@ -751,7 +752,11 @@ ApmPreInit(ScrnInfoPtr pScrn, int flags)
 	LinMap[0xFFECDB] = db;
 	LinMap[0xFFECD9] = d9;
 	/*pciWriteLong(pApm->PciTag, PCI_CMD_STAT_REG, save);*/
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)LinMap, pApm->LinMapSize);
+#else
+	pci_device_unmap_range(pApm->PciInfo, (pointer)LinMap, pApm->LinMapSize);
+#endif
 	from = X_PROBED;
     }
     else {
@@ -1134,12 +1139,19 @@ ApmUnmapMem(ScrnInfoPtr pScrn)
 	    WRXB(0xDB, pApm->db);
 	}
 	WRXB(0xC9, pApm->c9);
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pApm->LinMap, pApm->LinMapSize);
+#else
+	pci_device_unmap_range(pApm->PciInfo, (pointer)pApm->LinMap, pApm->LinMapSize);
+#endif
 	pApm->LinMap = NULL;
     }
     else if (pApm->FbBase)
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pApm->LinMap, 0x10000);
-
+#else
+	pci_device_unmap_range(pApm->PciInfo, (pointer)pApm->LinMap, 0x10000);
+#endif
     return TRUE;
 }
 
@@ -1784,7 +1796,6 @@ ApmScreenInit(SCREEN_INIT_ARGS_DECL)
     }
 #endif
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
