Index: programs/Xserver/hw/xfree86/drivers/trident/trident_driver.c
===================================================================
RCS file: /usr/local/repos/xfree86/xc/programs/Xserver/hw/xfree86/drivers/trident/trident_driver.c,v
retrieving revision 1.193
retrieving revision 1.194
diff -u -r1.193 -r1.194
--- programs/Xserver/hw/xfree86/drivers/trident/trident_driver.c	18 Feb 2005 02:55:10 -0000	1.193
+++ programs/Xserver/hw/xfree86/drivers/trident/trident_driver.c	30 Apr 2005 17:04:00 -0000	1.194
@@ -2606,7 +2606,7 @@
     TRIDENTPtr pTrident = TRIDENTPTR(pScrn);
     TRIDENTRegPtr tridentReg;
 
-    WAITFORVSYNC;
+    if (!xf86IsPc98()) WAITFORVSYNC;
 
     TridentFindClock(pScrn,mode->Clock);
 
