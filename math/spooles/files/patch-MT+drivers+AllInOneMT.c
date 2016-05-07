--- MT/drivers/allInOneMT.c.orig	1999-01-21 16:51:22 UTC
+++ MT/drivers/allInOneMT.c
@@ -35,7 +35,7 @@ DenseMtx        *mtxY, *mtxX ;
 Chv             *rootchv ;
 ChvManager      *chvmanager ;
 double          droptol = 0.0, tau = 100. ;
-double          cpus[10] ;
+double          cpus[11] ;	/* see MT/src/factor.c - Manfred Spraul */
 DV              *cumopsDV ;
 ETree           *frontETree ;
 FrontMtx        *frontmtx ;
