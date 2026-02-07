--- src/ast_driver.c.orig	2024-08-01 13:20:24 UTC
+++ src/ast_driver.c
@@ -273,6 +273,8 @@ ASTProbe(DriverPtr drv, int flags)
 
 #ifdef XSERVER_LIBPCIACCESS
             {
+#ifndef __FreeBSD__
+		/* FreeBSD always has vgapci driver attached.  */
                 struct pci_device *pPci = xf86GetPciInfoForEntity(usedChips[i]);
 
                 if (pci_device_has_kernel_driver(pPci)) {
@@ -289,6 +291,7 @@ ASTProbe(DriverPtr drv, int flags)
                     free(devSections);
                     return FALSE;
                 }
+#endif
             }
 #endif
 
