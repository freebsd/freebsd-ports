--- src/gfanlib_symmetriccomplex.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/gfanlib_symmetriccomplex.cpp
@@ -554,7 +554,7 @@ IntegerMatrix SymmetricComplex::boundaryMap(int d)
           static int t;
   //        log1 fprintf(Stderr,"Adding faces of cone %i\n",t++);
         }
-  //      log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
+  //      gfan_log2 fprintf(Stderr,"Dim: %i\n",i->dimension());
 
         addFacesToSymmetricComplex(symCom,*i,i->getHalfSpaces(),generatorsOfLinealitySpace);
       }
