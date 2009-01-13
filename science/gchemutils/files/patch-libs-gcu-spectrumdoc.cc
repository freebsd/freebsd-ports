--- libs/gcu/spectrumdoc.cc.orig	2009-01-05 20:09:59.000000000 +0100
+++ libs/gcu/spectrumdoc.cc	2009-01-13 16:22:00.000000000 +0100
@@ -1898,7 +1898,7 @@
 
 static double expm (double val, double f, double offset)
 {
-	return exp10 (-val) * f + offset;
+	return pow (10, -val) * f + offset;
 }
 
 double (*SpectrumDocument::GetConversionFunction (SpectrumUnitType oldu, SpectrumUnitType newu, double &factor, double &shift)) (double, double, double)
