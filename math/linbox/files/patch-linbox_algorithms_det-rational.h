--- linbox/algorithms/det-rational.h.orig	2019-06-07 13:22:08 UTC
+++ linbox/algorithms/det-rational.h
@@ -79,8 +79,8 @@ namespace LinBox
 	struct MyRationalModularDet {
 		const Blackbox &A;
 		const MyMethod &M;
-		const Integer &mul;//multiplicative prec;
-		const Integer &div;
+		Integer mul;//multiplicative prec;
+		Integer div;
 
 		MyRationalModularDet(const Blackbox& b, const MyMethod& n,
 				     const Integer & p1, const Integer & p2) :
