--- ntpd.c.orig	2015-01-08 06:57:55 UTC
+++ ntpd.c
@@ -515,7 +515,11 @@ readfreq(void)
 		log_warn("adjfreq failed");
 	else if (current == 0) {
 		if (fscanf(fp, "%le", &d) == 1)
-			ntpd_adjfreq(d, 0);
+			/*
+			 * Drift file in ppm for compatibility
+			 * with reference ntpd.
+			 */
+			ntpd_adjfreq(d / 1e6, 0);
 		else
 			log_warnx("can't read %s", DRIFTFILE);
 	}
@@ -538,7 +542,8 @@ writefreq(double d)
 		return 0;
 	}
 
-	fprintf(fp, "%e\n", d);
+	/* Drift file in ppm for compatibility with reference ntpd. */
+	fprintf(fp, "%e\n", d * 1e6);
 	r = ferror(fp);
 	if (fclose(fp) != 0 || r != 0) {
 		if (warnonce) {
