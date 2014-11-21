--- src/real.h.orig	2006-10-06 15:42:58.000000000 +0400
+++ src/real.h	2014-11-21 03:10:40.000000000 +0300
@@ -145,7 +145,7 @@
 	friend Real ipart(const Real &val) throw(error_obj);
 	friend Real fpart(const Real &val) throw(error_obj);
 	// converts a Real to a fraction
-	friend Real frac(const Real &val, int32 highest_bottom_value = 1000) throw(error_obj);
+	friend Real frac(const Real &val, int32 highest_bottom_value) throw(error_obj);
 	friend Real sign(const Real &val) throw(error_obj);
 
 	// val.isExact() must return true
