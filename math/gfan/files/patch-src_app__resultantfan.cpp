--- src/app_resultantfan.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_resultantfan.cpp
@@ -164,7 +164,7 @@ class ResultantFanApplication : public GFanApplication
               for(IntegerVectorList::const_iterator i=linealityGen.begin();i!=linealityGen.end();i++)temp.push_back(*i);
               for(IntegerVectorList::const_iterator i=gen.begin();i!=gen.end();i++)temp.push_back(*i);
 
-              if(::rank(rowsToIntegerMatrix(temp,N))!=N){log2 debug<<"Skipping\n";continue;}
+              if(::rank(rowsToIntegerMatrix(temp,N))!=N){gfan_log2 debug<<"Skipping\n";continue;}
             }
 
 
@@ -182,10 +182,10 @@ class ResultantFanApplication : public GFanApplication
           C.canonicalize();
    //       debug<<toNonSpecialSubspace(gen,*special);
   //        debug<<toNonSpecialSubspace(linealityGen,*special);
-          log2 debug<<":"<<C.dimension()<<"\n";
+          gfan_log2 debug<<":"<<C.dimension()<<"\n";
           if(C.dimension()==n-1)
             {
-              log2 debug<<"adding\n";
+              gfan_log2 debug<<"adding\n";
               F.push_back(C);
             }
         }
