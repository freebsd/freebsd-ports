--- drawbdmesh.cpp.orig	Fri Apr 24 09:39:12 1998
+++ drawbdmesh.cpp	Fri Dec 19 11:01:38 2003
@@ -16,7 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <setjmp.h>
-#include <new.h>
+#include <new>
 #include <assert.h>
 #include "Meshio.h"
 #include "Mesh2.h"
@@ -41,7 +41,7 @@
 //  DelAllocData();
   cout << "on a fini" << endl;
 }
-void  MeshErrorIO(ios& )
+void  MeshErrorIO(std::ios& )
 {
   MeshError(999);
   exit(1);
@@ -53,10 +53,10 @@
   //  atexit( forDebug);
   double raison=0;
   verbosity = 9;
-    set_new_handler( &NewHandler);
+    std::set_new_handler( &NewHandler);
    char * fmeshback= "1.mesh";
    char * fmetrix= 0; 
-    ostream *f_metr(&cout);
+    std::ostream *f_metr(&cout);
     if (argc >=2) 
      fmeshback = argv[1];
      if (argc >=3) 
