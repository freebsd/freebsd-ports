--- src/OpenMesh/Apps/Decimating/decimater.cc.orig	2020-03-12 13:55:53 UTC
+++ src/OpenMesh/Apps/Decimating/decimater.cc
@@ -53,6 +53,9 @@
 #include <string>
 #include <memory>
 #include <map>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 //--------------------
 #include <OpenMesh/Core/IO/MeshIO.hh>
 //--------------------
