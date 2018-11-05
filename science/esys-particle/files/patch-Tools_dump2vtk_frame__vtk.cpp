--- Tools/dump2vtk/frame_vtk.cpp.orig	2018-11-05 04:45:11 UTC
+++ Tools/dump2vtk/frame_vtk.cpp
@@ -1276,7 +1276,7 @@ void writeMeshFile(const string& infilen
   string header,skip;
   int numMeshIG;
 
-  while (datafile >> header != NULL){
+  while (datafile >> header){
     if (header == "TMIG"){
       datafile >> numMeshIG;
       for(int ni=0;ni<numMeshIG;ni++){
