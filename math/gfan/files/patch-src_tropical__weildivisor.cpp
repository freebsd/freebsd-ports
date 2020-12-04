--- src/tropical_weildivisor.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/tropical_weildivisor.cpp
@@ -53,7 +53,7 @@ PolyhedralFan weilDivisor(PolyhedralFan const &F, Poly
 
 	  AsciiPrinter P(Stderr);
 
-	  log2 P<<v<<v<<"\n";
+	  gfan_log2 P<<v<<v<<"\n";
 
 	  int multiplicity=0;
 	  IntegerVector evaluationVector(n);
