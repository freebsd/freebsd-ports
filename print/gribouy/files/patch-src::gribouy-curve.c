--- src/gribouy-curve.c.orig	Fri Aug 13 19:51:07 2004
+++ src/gribouy-curve.c	Fri Aug 13 19:51:21 2004
@@ -311,6 +311,7 @@
 			bp++;
 		}
 	next_one:
+		;
 	} while (bp->code != ART_END);
 	art_free (bpath);
 	if (vp)
