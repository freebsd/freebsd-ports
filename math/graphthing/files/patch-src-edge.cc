--- src/edge.cc.orig	Fri Oct 25 13:39:36 2002
+++ src/edge.cc	Fri Oct 25 13:40:19 2002
@@ -13,7 +13,7 @@
 			weight (wt), directed (dir), selected (false)
 {
 	if (a == b)
-		throw invalid_argument ("Loops not yet supported.");
+		throw std::invalid_argument ("Loops not yet supported.");
 }
 
 Edge::Edge (const Edge &other) : v (other.v), w (other.w),
