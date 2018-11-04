--- finish.cpp.orig	2018-11-02 06:42:25 UTC
+++ finish.cpp
@@ -719,7 +719,7 @@ void Finish::end(int flag)
 
     nneighfull = 0;
     if (m < neighbor->old_nrequest) {
-      if (neighbor->lists[m]->numneigh > 0) {
+      if (neighbor->lists[m]->numneigh) { // see https://www.cfdem.com/forums/error-non-const-lvalue-reference-type-basicostringstream-cannot-bind-temporary-type
         int inum = neighbor->lists[m]->inum;
         int *ilist = neighbor->lists[m]->ilist;
         int *numneigh = neighbor->lists[m]->numneigh;
