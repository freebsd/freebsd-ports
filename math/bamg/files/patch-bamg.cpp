--- bamg.cpp.orig	Thu Apr  5 10:08:53 2001
+++ bamg.cpp	Fri Dec 19 10:52:55 2003
@@ -18,13 +18,13 @@
 #include <stdio.h>
 #include <string.h>
 #include <setjmp.h>
-#include <new.h>
+#include <new>
 #include <assert.h>
 #include "Meshio.h"
-#include <iomanip.h>
+#include <iomanip>
 #include "Mesh2.h"
 #include "QuadTree.h"
-#include <fstream.h>
+#include <fstream>
 #ifdef __MWERKS__
 #define   NBVMAX 10000
 #else
@@ -67,7 +67,7 @@
 void forDebug();
 
 
-void  MeshErrorIO(ios& )
+void  MeshErrorIO(std::ios& )
 {
   MeshError(999);
   exit(1);
@@ -139,7 +139,7 @@
   const char * datafile = argc ==2 ? argv[1] : "DATA_bamg";
   
   atexit( forDebug);
-  set_new_handler( &NewHandler);
+  std::set_new_handler( &NewHandler);
 
   if (argc<3)  
     { // for test on the mac
@@ -495,10 +495,10 @@
 #endif
 	 time3 = CPUtime();
 	 if(verbosity> 1)
-	   cout << " Cpu for meshing         :" << setw(8) << time2-time1 
+	   cout << " Cpu for meshing         :" << std::setw(8) << time2-time1 
 		<< "s, for  Smoothing " <<  time3-time2 
 		<< "s  Nb Vertices/s = " <<  (Th.nbv) /(time2-time1)
-		<< setw(0) <<endl ;
+		<< std::setw(0) <<endl ;
 	 if (fmeshout) Th.Write(fmeshout  ,Triangles::BDMesh);
 	 if (famfmt)   Th.Write(famfmt    ,Triangles::am_fmtMesh);
 	 if (fam)      Th.Write(fam       ,Triangles::amMesh);
@@ -516,8 +516,8 @@
 	 time3 = CPUtime();
 	 if(verbosity>0) 
 	       {
-		 cout << " Cpu for meshing with io :" << setw(8) <<time3-time0 
-		      << "s  Nb Vertices/s = " <<  (Th.nbv) /(time3-time0)	 << setw(0)<< endl;
+		 cout << " Cpu for meshing with io :" << std::setw(8) <<time3-time0 
+		      << "s  Nb Vertices/s = " <<  (Th.nbv) /(time3-time0)	 << std::setw(0)<< endl;
 		 cout << " Nb vertices = " << Th.nbv;
 	       if (Th.nbt-Th.NbOutT-Th.NbOfQuad*2) 
 		 cout  << " Nb Triangles = " << (Th.nbt-Th.NbOutT-Th.NbOfQuad*2);
@@ -594,7 +594,7 @@
 	     if(verbosity >2)
 	       cout << " -- write Metric  file " << foM <<endl;
 		 
-	     ofstream f(foM);
+	     std::ofstream f(foM);
 	     if(f) BTh.WriteMetric(f,iso);
 	   }
 
@@ -672,8 +672,8 @@
 		     cerr << " Fatal Error "  << "solBB =  " <<  solBB << " solbb= " << solbb << endl;
 		     exit(2);}
 		 
-		 ofstream *fbb = wbb ? new ofstream(wbb) :0;
-		 ofstream *fBB = wBB ? new ofstream(wBB) :0;
+		 std::ofstream *fbb = wbb ? new std::ofstream(wbb) :0;
+		 std::ofstream *fBB = wBB ? new std::ofstream(wBB) :0;
 		 Int4   nbfieldBB = 0, nbfieldbb = nbsolbb;
 		 if (fbb)
 		   *fbb  << dim << " " << nbsolbb << " " << Th.nbv <<" " << 2 << endl; 
