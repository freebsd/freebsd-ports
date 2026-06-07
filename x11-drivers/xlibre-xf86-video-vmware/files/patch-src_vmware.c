--- src/vmware.c.orig	2025-12-18 18:24:45 UTC
+++ src/vmware.c
@@ -325,7 +325,7 @@ VMWAREPreInit(ScrnInfoPtr pScrn, int flags)
                    "No supported VMware SVGA found (read ID 0x%08x).\n", id);
         return FALSE;
     }
-    pVMWARE->suspensionSavedRegId = id;
+    pVMWARE->SavedReg.svga_reg_id = id;
 
     pVMWARE->Primary = xf86IsPrimaryPci(pVMWARE->PciInfo);
 
