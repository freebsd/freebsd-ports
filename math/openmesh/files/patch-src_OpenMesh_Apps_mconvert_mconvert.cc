--- src/OpenMesh/Apps/mconvert/mconvert.cc.orig	2020-03-12 13:55:54 UTC
+++ src/OpenMesh/Apps/mconvert/mconvert.cc
@@ -45,6 +45,9 @@
 #include <iterator>
 #include <fstream>
 #include <string>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 //
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
