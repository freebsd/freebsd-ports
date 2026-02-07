--- src/liflines/show.c.orig	2015-12-22 22:00:40 UTC
+++ src/liflines/show.c
@@ -254,7 +254,10 @@ disp_person_birthdeath (ZSTR zstr, RECORD irec, struct
 			zs_apps(ztemp, place);
 		}
 		if (!date && !place) {
-			zs_apps(ztemp, "Y");
+			// Git #308: INDI with BIRT/DEAT without DATE/PLAC displays "Y"
+			// The 3.0.62 behaviour was to display nothing.
+			// This sounds more appropriate so reverting to that behaviour.
+			//zs_apps(ztemp, "Y");
 		}
 		if (ct>1) {
 			zs_appf(ztemp, " (%d alt)", ct-1);
