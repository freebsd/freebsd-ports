--- bin/varnishhist/varnishhist.c.orig	2018-08-29 09:52:28 UTC
+++ bin/varnishhist/varnishhist.c
@@ -299,7 +299,7 @@ accumulate(struct VSL_data *vsl, struct VSL_transactio
 			continue;
 
 		/* select bucket */
-		i = HIST_RES * lround(log(value) / log_ten);
+		i = lround(HIST_RES * log(value) / log_ten);
 		if (i < hist_low * HIST_RES)
 			i = hist_low * HIST_RES;
 		if (i >= hist_high * HIST_RES)
