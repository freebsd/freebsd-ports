--- src/gfanlib_zfan.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/gfanlib_zfan.cpp
@@ -162,11 +162,11 @@ namespace gfan
 
         ZFan ret(sym);
 
-//        log2 cerr<< "Number of orbits to expand "<<cones.size()<<endl;
+//        gfan_log2 cerr<< "Number of orbits to expand "<<cones.size()<<endl;
         for(unsigned i=0;i<cones.size();i++)
         //  if(coneIndices==0 || coneIndices->count(i))
             {
-//              log2 cerr<<"Expanding symmetries of cone"<<endl;
+//              gfan_log2 cerr<<"Expanding symmetries of cone"<<endl;
               {
                 ZMatrix coneRays(0,n);
                 for(list<int>::const_iterator j=cones[i].begin();j!=cones[i].end();j++)
