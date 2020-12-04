--- src/codimoneconnectedness.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/codimoneconnectedness.cpp
@@ -33,6 +33,6 @@ bool CodimOneConnectednessTester::isConnected()const
       g.addEdge(facetIndex,nFacets+(lower_bound(allRidges2.begin(),allRidges2.end(),*j)-allRidges2.begin()));
 
   int diameter=g.diameter();
-  log2 cerr << "Diameter " << diameter << " nFacets " << nFacets << " nRidges " << nRidges << endl;
+  gfan_log2 cerr << "Diameter " << diameter << " nFacets " << nFacets << " nRidges " << nRidges << endl;
   return diameter<nFacets+nRidges;
 }
