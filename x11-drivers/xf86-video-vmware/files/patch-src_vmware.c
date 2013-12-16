--- src/vmware.c.orig	2013-12-16 11:39:54.616921846 +0100
+++ src/vmware.c	2013-12-16 11:40:27.592920514 +0100
@@ -365,7 +365,7 @@
                    "No supported VMware SVGA found (read ID 0x%08x).\n", id);
         return FALSE;
     }
-    pVMWARE->suspensionSavedRegId = id;
+    pVMWARE->SavedReg.svga_reg_id = id;
 
 #if !XSERVER_LIBPCIACCESS
     pVMWARE->PciTag = pciTag(pVMWARE->PciInfo->bus, pVMWARE->PciInfo->device,
