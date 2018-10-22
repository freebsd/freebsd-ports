--- src/OpenMesh/Apps/Subdivider/adaptive_subdivider.cc.orig	2018-10-21 23:38:04 UTC
+++ src/OpenMesh/Apps/Subdivider/adaptive_subdivider.cc
@@ -67,6 +67,9 @@
 #  include <cmath>
    using std::pow;
 #endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
   
 using OpenMesh::Subdivider::Adaptive::CompositeTraits;
