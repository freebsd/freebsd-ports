# Double in, double out; use fabs
#
--- src/neo_driver.c.orig	2016-11-25 03:32:57 UTC
+++ src/neo_driver.c
@@ -2952,7 +2952,7 @@ neoCalcVCLK(ScrnInfoPtr pScrn, long freq
 	for (n = 0; n <= MAX_N; n++)
 	    for (d = 1; d <= MAX_D; d++) {
 		f_out = (n+1.0)/((d+1.0)*(1<<f))*REF_FREQ;
-		f_diff = abs(f_out-f_target);
+		f_diff = fabs(f_out-f_target);
 		if (f_diff < f_best_diff) {
 		    f_best_diff = f_diff;
 		    n_best = n;
