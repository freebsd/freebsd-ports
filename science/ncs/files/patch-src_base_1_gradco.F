--- src/base_1/gradco.F.orig	Thu Mar  1 12:23:42 2007
+++ src/base_1/gradco.F	Sun Jun 17 15:01:40 2007
@@ -319,7 +319,7 @@
       RKGKM1 = RKGK
 C
 #if defined(_CS_HAVE_BLAS)
-      CALL DZAXPY(NCEL,RGSRG,DK,UN,GK,UN,DK,UN)
+      CALL CAXPY(NCEL,RGSRG,DK,UN,GK,UN,DK,UN)
 #else
       DO IEL=1,NCEL
         DK(IEL) = GK(IEL) +RGSRG*DK(IEL)
