$FreeBSD$

Drift file in ppm for compatibility with reference ntpd.

--- ntpd.c.orig	2009-11-23 20:34:47.000000000 +0100
+++ ntpd.c	2009-11-23 20:36:38.000000000 +0100
@@ -457,7 +457,7 @@ readfreq(void)
 		log_warn("adjfreq failed");
 	else if (current == 0) {
 		if (fscanf(fp, "%le", &d) == 1)
-			ntpd_adjfreq(d, 0);
+			ntpd_adjfreq(d / 1e6, 0);
 		else
 			log_warnx("can't read %s", DRIFTFILE);
 	}
@@ -480,7 +480,7 @@ writefreq(double d)
 		return 0;
 	}
 
-	fprintf(fp, "%e\n", d);
+	fprintf(fp, "%e\n", d * 1e6);
 	r = ferror(fp);
 	if (fclose(fp) != 0 || r != 0) {
 		if (warnonce) {
