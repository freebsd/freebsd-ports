--- trackdb/Track.cc.orig	Sun Nov 17 02:32:03 2002
+++ trackdb/Track.cc	Sun Nov 17 02:32:26 2002
@@ -41,7 +41,7 @@
   subTracks_ = lastSubTrack_ = NULL;
 
   nofIndices_ = 0;
-  index_ = new Msf[98](0);
+  index_ = new Msf[98];
 
   isrcValid_ = 0;
 
@@ -75,7 +75,7 @@
   }
 
   nofIndices_ = obj.nofIndices_;
-  index_ = new Msf[98](0);
+  index_ = new Msf[98];
   for (i = 0; i < nofIndices_; i++) {
     index_[i] = obj.index_[i];
   }
