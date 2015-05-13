--- histo_mex.cpp-orig	2015-04-17 13:59:47.874099000 +0000
+++ histo_mex.cpp	2015-03-30 20:52:08.000000000 +0000
@@ -109,7 +109,7 @@
 			float f1,f2;
 			f1 = ((float*)Sort.Table)[ix1];
 			f2 = ((float*)Sort.Table)[ix2];
-			z = __isnanf(f1) - __isnanf(f2);
+			z = isnanf(f1) - isnanf(f2);
 			if (z) break;
 			
 			if (f1<f2) z = -1; 
@@ -121,7 +121,7 @@
 			double f1,f2;
 			f1 = ((double*)Sort.Table)[ix1];
 			f2 = ((double*)Sort.Table)[ix2];
-			z = __isnan(f1) - __isnan(f2);
+			z = isnan(f1) - isnan(f2);
 			if (z) break;
 			
 			if (f1<f2) z = -1; 
