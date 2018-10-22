--- src/OpenMesh/Apps/VDProgMesh/mkbalancedpm/mkbalancedpm.cc.orig	2018-10-21 23:38:43 UTC
+++ src/OpenMesh/Apps/VDProgMesh/mkbalancedpm/mkbalancedpm.cc
@@ -50,6 +50,9 @@
 #include <iostream>
 #include <sstream>
 #include <cmath>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // -------------------- OpenMesh
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
