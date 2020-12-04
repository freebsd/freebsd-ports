--- src/app_secondaryfan.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_secondaryfan.cpp
@@ -385,7 +385,7 @@ class SecondaryFanApplication : public GFanApplication
 		    for(PolyhedralFan::coneIterator i=f1.conesBegin();i!=f1.conesEnd();i++)
 			{
 		    	static int a;
-		    	log2 cerr<<"Processing Cone "<<a++<<" which has dimension "<<i->dimension()<<endl;
+		    	gfan_log2 cerr<<"Processing Cone "<<a++<<" which has dimension "<<i->dimension()<<endl;
 		    	SecondaryFanTraverser traverser(triangulationWithFullDimensionalIntersection(t,*i),*i);
 				SymmetricTargetCounterInterrupted target2(target,optionInterrupt.getValue());
 				symmetricTraverse(traverser,target2,&s);
