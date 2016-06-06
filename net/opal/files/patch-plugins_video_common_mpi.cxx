--- plugins/video/common/mpi.cxx.orig	2013-02-20 02:18:05 UTC
+++ plugins/video/common/mpi.cxx
@@ -132,8 +132,8 @@ bool MPIList::getNegotiatedMPI( unsigned
   // to the desired one or matches it
   for (i=0; i < MPIs.size(); i++) {
     // we square the value in order to get absolute distances
-    distance = ( abs(MPIs[i].width  - desiredWidth ) *
-                 abs(MPIs[i].height - desiredHeight) );
+    distance = ( abs((int)(MPIs[i].width  - desiredWidth )) *
+                 abs((int)(MPIs[i].height - desiredHeight)) );
 
     if (distance < minDistance) {
       minDistance = distance;
