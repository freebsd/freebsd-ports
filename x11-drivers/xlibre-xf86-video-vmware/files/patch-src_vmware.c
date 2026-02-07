--- src/vmware.c.orig	2018-05-17 07:42:24 UTC
+++ src/vmware.c
@@ -381,7 +381,7 @@ VMWAREPreInit(ScrnInfoPtr pScrn, int fla
                    "No supported VMware SVGA found (read ID 0x%08x).\n", id);
         return FALSE;
     }
-    pVMWARE->suspensionSavedRegId = id;
+    pVMWARE->SavedReg.svga_reg_id = id;
 
 #if !XSERVER_LIBPCIACCESS
     pVMWARE->PciTag = pciTag(pVMWARE->PciInfo->bus, pVMWARE->PciInfo->device,
