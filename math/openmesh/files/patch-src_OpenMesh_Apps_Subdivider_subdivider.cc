--- src/OpenMesh/Apps/Subdivider/subdivider.cc.orig	2020-03-12 13:55:53 UTC
+++ src/OpenMesh/Apps/Subdivider/subdivider.cc
@@ -43,6 +43,9 @@
 
 #include <iostream>
 #include <sstream>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 // ---------------------------------------- OpenMesh Stuff
 #include <OpenMesh/Core/IO/MeshIO.hh>
 #include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
