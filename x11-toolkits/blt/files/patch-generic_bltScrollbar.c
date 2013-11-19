--- generic/bltScrollbar.c.orig	2013-10-30 11:57:57.000000000 +0100
+++ generic/bltScrollbar.c	2013-10-30 11:59:06.000000000 +0100
@@ -588,7 +588,7 @@
 	} else {
 	    fraction = ((double)pixels / (double)barWidth);
 	}
-	sprintf(interp->result, "%g", fraction);
+	Tcl_SetObjResult(interp, Tcl_NewDoubleObj(fraction));
     } else if ((c == 'f') && (strncmp(argv[1], "fraction", length) == 0)) {
 	int x, y, pos, barWidth;
 	double fraction;
