--- src/core/CLucene/index/DocumentsWriter.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/DocumentsWriter.cpp	2012-08-07 17:23:51.000000000 -0400
@@ -125,7 +125,7 @@
   if (this->postingsFreeListDW.values){
       if (this->postingsFreeCountDW < this->postingsFreeListDW.length) {
           memset(this->postingsFreeListDW.values + this->postingsFreeCountDW
-              , NULL
+              , 0
               , sizeof(Posting*));
       }
       postingsFreeListDW.deleteUntilNULL();
