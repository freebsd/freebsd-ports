--- src/OpenMesh/Apps/Decimating/decimater.cc.orig	2018-10-21 23:36:03 UTC
+++ src/OpenMesh/Apps/Decimating/decimater.cc
@@ -58,6 +58,9 @@
 #include <string>
 #include <memory>
 #include <map>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 //--------------------
 #include <OpenMesh/Core/IO/MeshIO.hh>
 //--------------------
