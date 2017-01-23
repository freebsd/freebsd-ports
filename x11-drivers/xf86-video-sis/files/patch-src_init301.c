# Fix an uninitialized variable
# Remove some dead code to eliminate a style warning
#
--- src/init301.c.orig	2010-03-07 19:36:10 UTC
+++ src/init301.c
@@ -446,7 +446,7 @@ SiS_CR36BIOSWord23d(struct SiS_Private *
 void
 SiS_DDC2Delay(struct SiS_Private *SiS_Pr, unsigned int delaytime)
 {
-   unsigned int i, j;
+   unsigned int i, j = 0;
 
    for(i = 0; i < delaytime; i++) {
       j += SiS_GetReg(SiS_Pr->SiS_P3c4,0x05);
@@ -534,9 +534,7 @@ SiS_PanelDelay(struct SiS_Private *SiS_P
 	    SiS_DDC2Delay(SiS_Pr, 0x4000);
 	 }
 
-      } else if((SiS_Pr->SiS_IF_DEF_LVDS == 1) /* ||
-	 (SiS_Pr->SiS_CustomT == CUT_COMPAQ1280) ||
-	 (SiS_Pr->SiS_CustomT == CUT_CLEVO1400) */ ) {			/* 315 series, LVDS; Special */
+      } else if(SiS_Pr->SiS_IF_DEF_LVDS == 1) {				/* 315 series, LVDS; Special */
 
 	 if(SiS_Pr->SiS_IF_DEF_CH70xx == 0) {
 	    PanelID = SiS_GetReg(SiS_Pr->SiS_P3d4,0x36);
