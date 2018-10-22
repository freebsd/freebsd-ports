--- src/OpenMesh/Apps/Subdivider/subdivider.cc.orig	2018-10-21 23:37:26 UTC
+++ src/OpenMesh/Apps/Subdivider/subdivider.cc
@@ -48,6 +48,9 @@
 
 #include <iostream>
 #include <sstream>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // ---------------------------------------- OpenMesh Stuff
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
