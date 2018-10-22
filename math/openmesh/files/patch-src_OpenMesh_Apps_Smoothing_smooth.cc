--- src/OpenMesh/Apps/Smoothing/smooth.cc.orig	2018-10-21 23:39:56 UTC
+++ src/OpenMesh/Apps/Smoothing/smooth.cc
@@ -53,6 +53,9 @@
 #include <OpenMesh/Tools/Utils/Timer.hh>
 #include <OpenMesh/Tools/Smoother/JacobiLaplaceSmootherT.hh>
 #include <OpenMesh/Tools/Utils/getopt.h>
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
 
 using namespace OpenMesh;
