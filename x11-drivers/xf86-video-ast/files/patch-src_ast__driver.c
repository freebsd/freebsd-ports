--- src/ast_driver.c.orig	2025-08-09 00:45:40 UTC
+++ src/ast_driver.c
@@ -259,6 +259,8 @@ ASTProbe(DriverPtr drv, int flags)
 
 #ifdef XSERVER_LIBPCIACCESS
             {
+#ifndef __FreeBSD__
+		/* FreeBSD always has vgapci driver attached.  */
                 struct pci_device *pPci = xf86GetPciInfoForEntity(usedChips[i]);
 
                 if (pci_device_has_kernel_driver(pPci)) {
@@ -271,6 +273,7 @@ ASTProbe(DriverPtr drv, int flags)
                     free(devSections);
                     return FALSE;
                 }
+#endif
             }
 #endif
 
