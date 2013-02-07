--- icb/oset.c.orig	2000-12-15 12:21:03.000000000 +0900
+++ icb/oset.c	2012-10-25 18:15:16.000000000 +0900
@@ -61,7 +61,7 @@
 
 
 void
-restrict(void)
+icb_restrict(void)
 {
 	gv.restricted = 1;
 	tclrestrict();
@@ -91,7 +91,7 @@
 		if (gv.restricted)
 			TRETURNERR("oset: restricted mode can't be reset")
 		else {
-			restrict();
+			icb_restrict();
 			return(TCL_OK);
 		}
 	}
