--- view.c	Sat Jul 12 20:53:25 1997
+++ view.c	Sat Mar 22 18:24:31 2003
@@ -47,7 +47,7 @@
 	int sline, soff;                        /* search position */
 
 	baseline = basecol = 0;
-	while (viewrec->lindex[baseline+1].seek < viewseek)
+	while (viewrec->lindex[baseline].len != -1 && viewrec->lindex[baseline+1].seek < viewseek)
 		++baseline;
 	while (viewrec->lindex[baseline].seek + offset (baseline, basecol) + 40 < viewseek)
 		basecol += 40;
