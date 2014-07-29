--- lib/tfmfont.c.orig	1989-11-15 13:20:03.000000000 +0100
+++ lib/tfmfont.c	2012-11-30 15:00:41.000000000 +0100
@@ -139,7 +139,7 @@
 fail:
 	(void) fclose(fd);
 	if (tfm != NULL) {
-	  free((char *) tfm); (char *) tfm = 0;
+	  free((char *) tfm); tfm = 0;
 	}
 	return (-1);
 }
@@ -199,7 +199,7 @@
 #define EDGE 2
 
 	if (tfm->tfm_edge == 0)
-		return;
+		return (-1);
 if (tfm->tfm_edge != 2) panic("tfm_rasterise");
 	for (i = l; i < h; i++) {
 		g = f->f_gly[i];
