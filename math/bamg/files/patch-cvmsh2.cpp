--- cvmsh2.cpp.orig	Tue Jun  2 13:21:43 1998
+++ cvmsh2.cpp	Fri Dec 19 10:55:43 2003
@@ -16,7 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <setjmp.h>
-#include <new.h>
+#include <new>
 #include <assert.h>
 #include "Meshio.h"
 #include "Mesh2.h"
@@ -42,7 +42,7 @@
 }
 
 
-void  MeshErrorIO(ios& )
+void  MeshErrorIO(std::ios& )
 {
   MeshError(999);
   exit(1);
@@ -94,7 +94,7 @@
       return 1;
     }
   MeshIstreamErrorHandler = MeshErrorIO;
-  set_new_handler( &NewHandler);
+  std::set_new_handler( &NewHandler);
 #ifdef DRAWING 
   initgraphique(); 
   initgraph=1;
