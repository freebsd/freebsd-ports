--- MT/drivers/allInOneMT.c.orig	Sat Aug  9 14:06:19 2003
+++ MT/drivers/allInOneMT.c	Sat Aug  9 14:13:07 2003
@@ -35,7 +35,7 @@
 Chv             *rootchv ;
 ChvManager      *chvmanager ;
 double          droptol = 0.0, tau = 100. ;
-double          cpus[10] ;
+double          cpus[11] ;	/* see MT/src/factor.c - Manfred Spraul */
 DV              *cumopsDV ;
 ETree           *frontETree ;
 FrontMtx        *frontmtx ;
