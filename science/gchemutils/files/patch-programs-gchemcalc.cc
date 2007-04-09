--- programs/gchemcalc.cc.orig	Sat Feb 25 18:35:50 2006
+++ programs/gchemcalc.cc	Mon Mar 20 18:22:41 2006
@@ -140,7 +140,7 @@
 		} else {
 			if (prec < 0) {
 				// round the value to replace not significant figures by 0s.
-				double offs = pow10 (prec);
+				double offs = pow (10.0, prec);
 				weight = rint (weight * offs) / offs;
 			}
 			format = artificial? g_strdup ("(%.0f)"): g_strdup ("%.0f");
