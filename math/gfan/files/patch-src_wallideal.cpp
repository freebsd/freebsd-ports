--- src/wallideal.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/wallideal.cpp
@@ -1055,7 +1055,7 @@ IntegerVectorList fastNormals(IntegerVectorList const 
   //  log0 fprintf(Stderr,"Number of inequalities:%i\n",normals.size());
 
   //  log0 fprintf(Stderr,"G");
-  //log2 cerr << "Fast normals end" << endl;
+  //gfan_log2 cerr << "Fast normals end" << endl;
   return normals;
 }
 
