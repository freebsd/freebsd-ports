--- src/singular.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/singular.cpp
@@ -115,10 +115,10 @@ ring R=mySingularRingDegRevLex(idealGenerators.getRing
         test|=(Sy_bit(OPT_REDSB)|Sy_bit(OPT_REDTAIL)|Sy_bit(OPT_INTSTRATEGY));
         test|=(Sy_bit(OPT_REDTHROUGH));
 
-	log2 cerr<<"calling singular\n";
+	gfan_log2 cerr<<"calling singular\n";
 	//  debug<<"test"<<int(test)<<"\n";
 	ideal j=kStd(i,NULL,testHomog,NULL);
-	log2 cerr<<"returning from singular\n";
+	gfan_log2 cerr<<"returning from singular\n";
 
 	idDelete(&i);
 	ret=fromSingularIdeal(ret.getRing(),j,R);
@@ -175,10 +175,10 @@ ring R=mySingularRingDegRevLex(idealGenerators.getRing
     ideal i=singularPolynomialSet(idealGenerators);
     test|=(Sy_bit(OPT_REDSB)|Sy_bit(OPT_REDTAIL)|Sy_bit(OPT_INTSTRATEGY));
 
-    log2 cerr<<"calling singular\n";
+    gfan_log2 cerr<<"calling singular\n";
     ideal j=kStd(i,NULL,testHomog,NULL);
 	//    ideal j=kInterRed(i);
-    log2 cerr<<"returning from singular\n";
+    gfan_log2 cerr<<"returning from singular\n";
 
     idDelete(&i);
     ret=fromSingularIdeal(ret.getRing(),j,R);
