--- fig2dev/dev/genps.c.orig	2020-08-25 12:22:17 UTC
+++ fig2dev/dev/genps.c
@@ -96,8 +96,10 @@ static float	fllx, flly, furx, fury;
 /* arrowhead arrays */
 Point		bpoints[50], fpoints[50];
 int		nbpoints, nfpoints;
-Point		bfillpoints[50], ffillpoints[50], clippoints[50];
-int		nbfillpoints, nffillpoints, nclippoints;
+Point		bfillpoints[50], ffillpoints[50];
+int		nbfillpoints, nffillpoints;
+extern int	nclippoints;
+extern Point	clippoints[50];
 int		fpntx1, fpnty1;	/* first point of object */
 int		fpntx2, fpnty2;	/* second point of object */
 int		lpntx1, lpnty1;	/* last point of object */
