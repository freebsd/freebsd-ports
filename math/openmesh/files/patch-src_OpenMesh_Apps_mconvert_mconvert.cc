--- src/OpenMesh/Apps/mconvert/mconvert.cc.orig	2018-10-21 23:39:10 UTC
+++ src/OpenMesh/Apps/mconvert/mconvert.cc
@@ -50,6 +50,9 @@
 #include <iterator>
 #include <fstream>
 #include <string>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 //
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
