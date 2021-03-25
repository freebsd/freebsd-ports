--- src/OpenMesh/Apps/VDProgMesh/mkbalancedpm/mkbalancedpm.cc.orig	2020-03-12 13:55:54 UTC
+++ src/OpenMesh/Apps/VDProgMesh/mkbalancedpm/mkbalancedpm.cc
@@ -45,6 +45,9 @@
 #include <iostream>
 #include <sstream>
 #include <cmath>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // -------------------- OpenMesh
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
