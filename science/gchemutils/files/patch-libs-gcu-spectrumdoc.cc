--- libs/gcu/spectrumdoc.cc.orig	2009-01-05 14:09:59.000000000 -0500
+++ libs/gcu/spectrumdoc.cc	2009-05-09 15:06:20.000000000 -0400
@@ -1898,7 +1899,7 @@ static double logm (double val, double f
 
 static double expm (double val, double f, double offset)
 {
-	return exp10 (-val) * f + offset;
+	return pow (10, -val) * f + offset;
 }
 
 double (*SpectrumDocument::GetConversionFunction (SpectrumUnitType oldu, SpectrumUnitType newu, double &factor, double &shift)) (double, double, double)
