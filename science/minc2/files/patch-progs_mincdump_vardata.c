--- progs/mincdump/vardata.c.orig	2012-09-24 17:35:36 UTC
+++ progs/mincdump/vardata.c
@@ -775,7 +775,7 @@ vardata(
 
 	if (vrank > 0) {
 	    corsav = cor[vrank-1];
-	    if (fsp->brief_data_cmnts != false
+	    if (fsp->brief_data_cmnts != my_false
 		&& vrank > 1
 		&& left > 0) {	/* print brief comment with indices range */
 		Printf("// %s(",vp->name);
