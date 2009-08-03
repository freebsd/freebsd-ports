$FreeBSD$

Drift file in ppm for compatibility with reference ntpd.

--- ntpd.c.orig	2009-08-01 22:17:42.000000000 +0200
+++ ntpd.c	2009-08-01 22:18:51.000000000 +0200
@@ -449,7 +449,7 @@ readfreq(void)
 		log_warn("adjfreq failed");
 	else if (current == 0) {
 		if (fscanf(fp, "%le", &d) == 1)
-			ntpd_adjfreq(d, 0);
+			ntpd_adjfreq(d / 1e6, 0);
 	}
 	fclose(fp);
 }
@@ -470,7 +470,7 @@ writefreq(double d)
 		return 0;
 	}
 
-	fprintf(fp, "%e\n", d);
+	fprintf(fp, "%e\n", d * 1e6);
 	r = ferror(fp);
 	if (fclose(fp) != 0 || r != 0) {
 		if (warnonce) {
