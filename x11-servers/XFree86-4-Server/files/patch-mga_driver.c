Index: programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c,v
retrieving revision 1.250
retrieving revision 1.251
diff -u -r1.250 -r1.251
--- programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c	18 Feb 2005 02:55:08 -0000	1.250
+++ programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c	26 Apr 2005 00:56:43 -0000	1.251
@@ -401,7 +401,7 @@
   "MGASetVgaMode",
   "MGAValidateMode",
   "MGAValidateVideoParameters",
-  "MGASetDisplayStart",
+  "HALSetDisplayStart",
   NULL
 };
 #endif
@@ -3644,7 +3644,7 @@
         MGAAdjustGranularity(pScrn,&x,&y);
 	    pMga->HALGranularityOffX = pMga->HALGranularityOffX - x;
 	    pMga->HALGranularityOffY = pMga->HALGranularityOffY - y;
-        MGASetDisplayStart(pMga->pBoard,x,y,0);
+        HALSetDisplayStart(pMga->pBoard,x,y,0);
     );
 #endif
     MGA_NOT_HAL(
@@ -3692,7 +3692,7 @@
 #ifdef USEMGAHAL
     MGA_HAL(
         MGAAdjustGranularity(pScrn,&x,&y);
-        MGASetDisplayStart(pMga->pBoard,x,y,1);
+        HALSetDisplayStart(pMga->pBoard,x,y,1);
     );
 #endif
     MGA_NOT_HAL(
