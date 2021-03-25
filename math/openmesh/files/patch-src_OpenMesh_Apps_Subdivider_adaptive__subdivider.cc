--- src/OpenMesh/Apps/Subdivider/adaptive_subdivider.cc.orig	2020-03-12 13:55:53 UTC
+++ src/OpenMesh/Apps/Subdivider/adaptive_subdivider.cc
@@ -62,6 +62,9 @@
 #  include <cmath>
    using std::pow;
 #endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
   
 using OpenMesh::Subdivider::Adaptive::CompositeTraits;
