--- src/ast_vgatool.c.orig	2015-08-19 01:24:48.000000000 +0000
+++ src/ast_vgatool.c		2020-09-17 14:19:18.843298000 +0000
@@ -432,11 +432,27 @@
     *(ULONG *) (pAST->MMIOVirtualAddr + 0xF004) = 0x1e6e0000;
     *(ULONG *) (pAST->MMIOVirtualAddr + 0xF000) = 0x1;
 
+    /* Based on the Linux DRM driver we might not be able to access this
+     * If we can't just use some sane defaults.
+     *
+     * See drm/drivers/gpu/drm/ast/ast_main.c line 295.
+     */
+
     *(ULONG *) (pAST->MMIOVirtualAddr + 0x10000) = 0xFC600309;
-    do {
-       ;
-    } while (*(volatile ULONG *) (pAST->MMIOVirtualAddr + 0x10000) != 0x01);
+    for (ulData = 10000; ulData > 0; ulData--)
+	if (*(volatile ULONG *) (pAST->MMIOVirtualAddr + 0x10000) == 0x01)
+	    break;
 
+    if (ulData == 0) {
+	xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Unable to read DRAM information, using defaults\n");
+	pAST->ulDRAMBusWidth = 16;
+	pAST->jDRAMType = DRAMTYPE_1Gx16;
+	if (pAST->jChipType == AST2500)
+	    pAST->ulMCLK = 800;
+	else
+	    pAST->ulMCLK = 396;
+	return;
+    }
     ulData = *(volatile ULONG *) (pAST->MMIOVirtualAddr + 0x10004);
 
     /* Get BusWidth */
