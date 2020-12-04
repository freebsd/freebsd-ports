--- src/app_fiberpolytope.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_fiberpolytope.cpp
@@ -166,7 +166,7 @@ class FiberPolytopeApplication : public GFanApplicatio
 		    for(PolyhedralFan::coneIterator i=f1.conesBegin();i!=f1.conesEnd();i++)
 			{
 		    	static int a;
-		    	log2 cerr<<"Processing Cone "<<a++<<" which has dimension "<<i->dimension()<<endl;
+		    	gfan_log2 cerr<<"Processing Cone "<<a++<<" which has dimension "<<i->dimension()<<endl;
 		    	SecondaryFanTraverser traverser(triangulationWithFullDimensionalIntersection(t,*i),*i);
 				symmetricTraverse(traverser,target,&s);
 			}
