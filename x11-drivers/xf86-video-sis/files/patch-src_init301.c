--- src/init301.c.orig	2015-11-19 15:53:05.412011000 +0100
+++ src/init301.c	2015-11-19 15:53:24.734403000 +0100
@@ -446,7 +446,7 @@ SiS_CR36BIOSWord23d(struct SiS_Private *
 void
 SiS_DDC2Delay(struct SiS_Private *SiS_Pr, unsigned int delaytime)
 {
-   unsigned int i, j;
+   unsigned int i, j = 0;
 
    for(i = 0; i < delaytime; i++) {
       j += SiS_GetReg(SiS_Pr->SiS_P3c4,0x05);
