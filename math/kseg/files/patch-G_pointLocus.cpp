--- G_pointLocus.cpp.orig	Sat Nov 29 04:52:07 2003
+++ G_pointLocus.cpp	Sat Nov 29 04:54:38 2003
@@ -283,7 +283,7 @@
     }
     else discontCount = 0; //number of times the goodness decreased--for finding discontinuities
 
-    if(discontCount > log(maxSamples) / 1.5) {
+    if(discontCount > log((double)maxSamples) / 1.5) {
       points[0].loc = G_point::inValid();
       points[points[0].next].loc = G_point::inValid();
       points[points[0].prev].loc = G_point::inValid();
