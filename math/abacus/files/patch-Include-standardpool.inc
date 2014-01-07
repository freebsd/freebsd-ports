--- Include/abacus/standardpool.inc.orig	2013-11-16 14:06:39.000000000 +0100
+++ Include/abacus/standardpool.inc	2013-11-16 14:08:30.000000000 +0100
@@ -129,7 +129,7 @@
 
     for(int i = 0; i < ABA_POOL<BaseType, CoType>::number(); i++) 
       {
-      if(softDeleteConVar(pool_[i]) == 0)
+      if(this->softDeleteConVar(pool_[i]) == 0)
         {
          nDeleted++;
 	 // consider the case that a slot has been deleted although it was empty
@@ -179,7 +179,7 @@
     
     while(nRemoved < maxRemove && !candidates.empty()) {
       c = candidates.extractMin();  
-      hardDeleteConVar(pool_[c]);
+      this->hardDeleteConVar(pool_[c]);
       nRemoved++;
     }
 
