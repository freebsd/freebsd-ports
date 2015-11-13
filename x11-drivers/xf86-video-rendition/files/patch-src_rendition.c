--- src/rendition.c.orig	2015-10-11 22:31:51.242126000 +0200
+++ src/rendition.c	2015-10-11 22:32:20.465605000 +0200
@@ -1173,7 +1173,6 @@ renditionScreenInit(SCREEN_INIT_ARGS_DEC
     fbPictureInit (pScreen, 0, 0);
 
     xf86SetBlackWhitePixels(pScreen);
-    miInitializeBackingStore(pScreen);
    
     /*********************************************************/
     /* The actual setup of the driver-specific code          */
@@ -1372,6 +1371,18 @@ renditionMapMem(ScrnInfoPtr pScreenInfo)
        /* Override on users request */
     WriteCombine
 	= xf86ReturnOptValBool(pRendition->Options, OPTION_FBWC, WriteCombine);
+#ifdef XSERVER_LIBPCIACCESS
+    mapOption = PCI_DEV_MAP_FLAG_WRITABLE;
+    if (WriteCombine)
+	mapOption |= PCI_DEV_MAP_FLAG_WRITE_COMBINE;
+
+    err = pci_device_map_range(pRendition->PciInfo,
+			       pRendition->PciInfo->regions[0].base_addr,
+			       pRendition->PciInfo->regions[0].size,
+			       mapOption, (void *)&pRendition->board.vmem_base);
+
+    return (err == 0);
+#else
     if (WriteCombine) {
 	xf86DrvMsg(pScreenInfo->scrnIndex, X_CONFIG,
 		   ("Requesting Write-Combined memory access\n"));
@@ -1382,12 +1393,6 @@ renditionMapMem(ScrnInfoPtr pScreenInfo)
 	mapOption = VIDMEM_MMIO;
     }
 
-#ifdef XSERVER_LIBPCIACCESS
-    err = pci_device_map_region(pRendition->PciInfo, 0, TRUE);
-    pRendition->board.vmem_base = pRendition->PciInfo->regions[0].memory;
-
-    return (err == 0);
-#else
     pRendition->board.vmem_base=
         xf86MapPciMem(pScreenInfo->scrnIndex, mapOption,
 		      pRendition->pcitag,
@@ -1416,7 +1421,7 @@ renditionUnmapMem(ScrnInfoPtr pScreenInf
 #else
     pci_device_unmap_range(pRendition->PciInfo, 
 			   pRendition->board.vmem_base,
-			   pScreenInfo->videoRam * 1024);
+			   pRendition->PciInfo->regions[0].size);
 #endif
     return TRUE;
 #ifdef DEBUG0
