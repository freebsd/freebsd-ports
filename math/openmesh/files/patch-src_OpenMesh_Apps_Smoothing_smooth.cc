--- src/OpenMesh/Apps/Smoothing/smooth.cc.orig	2020-03-12 13:55:53 UTC
+++ src/OpenMesh/Apps/Smoothing/smooth.cc
@@ -48,6 +48,9 @@
 #include <OpenMesh/Tools/Utils/Timer.hh>
 #include <OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT.hh>
 #include <OpenMesh/Tools/Utils/getopt.h>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
 
 using namespace OpenMesh;
