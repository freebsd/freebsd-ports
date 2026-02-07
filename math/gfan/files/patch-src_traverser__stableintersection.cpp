--- src/traverser_stableintersection.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/traverser_stableintersection.cpp
@@ -62,7 +62,7 @@ IntegerVectorList StableIntersectionTraverser::link(In
 
 	IntegerVectorList rays1=theLink.getRaysInPrintingOrder(0);
 
-	log2 {
+	gfan_log2 {
 	  cerr<<"Ray candidates:"<<endl;
 	  AsciiPrinter(Stderr)<<rays1;
 	}
@@ -80,7 +80,7 @@ IntegerVectorList StableIntersectionTraverser::link(In
 			rays2.push_back(ray.getUniquePoint());
 			//			rays2.push_back(*i);
 			}
-	log2{
+	gfan_log2{
 	cerr<<"True rays:"<<endl;
 	AsciiPrinter(Stderr)<<rays2;
 	}
