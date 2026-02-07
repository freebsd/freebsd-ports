--- src/linalg.cpp.orig	2017-09-08 14:13:16 UTC
+++ src/linalg.cpp
@@ -885,7 +885,7 @@ IntegerVector vectorInKernel(IntegerMatrix const &m) /
 		return ret;
 	}
 	fallback:
-	log2 debug << "LINALG FALLBACK\n";
+	gfan_log2 debug << "LINALG FALLBACK\n";
 
 
   FieldMatrix m2=integerMatrixToFieldMatrix(m,Q);
