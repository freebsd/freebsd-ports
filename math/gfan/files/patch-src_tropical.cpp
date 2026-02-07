--- src/tropical.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/tropical.cpp
@@ -241,7 +241,7 @@ bool containsMonomialDehomogenize(PolynomialSet const 
 
 bool containsMonomial(PolynomialSet const &ideal)
 {
-	log2 debug<<"containsMonomial() called on input ideal:\n"<<ideal;
+	gfan_log2 debug<<"containsMonomial() called on input ideal:\n"<<ideal;
 
 //	if(ideal.empty())return false;
 
