--- ./libemc2_4.c.orig	1999-11-09 15:58:26.000000000 +0100
+++ ./libemc2_4.c	2012-08-24 13:40:38.364914711 +0200
@@ -2019,7 +2019,7 @@
 	libre = alloc_();
 	cdesig_1.adr = libre;
 	if (cdesig_1.adr == 0) {
-	    return ;
+	    return 0;
 	}
 /* Computing MAX */
 	r__1 = dabs(res[1]), r__2 = dabs(res[2]), r__1 = max(r__1,r__2), r__2 
