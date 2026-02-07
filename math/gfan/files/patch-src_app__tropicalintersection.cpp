--- src/app_tropicalintersection.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_tropicalintersection.cpp
@@ -37,7 +37,7 @@ class SymmetricTargetTropicalBasisTester : public Symm
 	bool process(ConeTraverser &traverser)
 	{
 		IntegerVector w=traverser.refToPolyhedralCone().getRelativeInteriorPoint();
-		log2 AsciiPrinter(Stderr) << "Testing weight vector:\n"<<w<<"\n";
+		gfan_log2 AsciiPrinter(Stderr) << "Testing weight vector:\n"<<w<<"\n";
 		WeightReverseLexicographicTermOrder T(w);
 		buchberger(&g,T);
 		PolynomialSet temp=initialForms(g,w);
