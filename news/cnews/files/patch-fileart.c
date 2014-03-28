--- relay/fileart.c.orig	1995-04-28 02:51:36.000000000 +0200
+++ relay/fileart.c	2014-02-07 17:03:01.000000000 +0100
@@ -791,7 +805,7 @@
 		canthappen(art, 'i',
 			"mkcopies called with ST_REFUSED set (can't happen)", "");
 	if (links == NULL)	/* fileart failed? */
-		return;
+		return 0;
 
 	/* fill in any empty links */
 	for (lp = link1; lp < linklim; lp++) {
@@ -807,4 +821,5 @@
 		nnfree(&lp->l_num);
 	}
 	free((char *)links);
+	return 0;
 }
