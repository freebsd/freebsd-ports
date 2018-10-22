--- src/OpenMesh/Apps/VDProgMesh/Analyzer/vdpmanalyzer.cc.orig	2018-10-21 23:40:29 UTC
+++ src/OpenMesh/Apps/VDProgMesh/Analyzer/vdpmanalyzer.cc
@@ -56,6 +56,9 @@
 #include <limits>
 #include <exception>
 #include <cmath>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // -------------------- OpenMesh
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
