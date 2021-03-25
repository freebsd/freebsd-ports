--- src/OpenMesh/Apps/VDProgMesh/Analyzer/vdpmanalyzer.cc.orig	2020-03-12 13:55:54 UTC
+++ src/OpenMesh/Apps/VDProgMesh/Analyzer/vdpmanalyzer.cc
@@ -51,6 +51,9 @@
 #include <limits>
 #include <exception>
 #include <cmath>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // -------------------- OpenMesh
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
