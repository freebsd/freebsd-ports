--- src/OpenMesh/Apps/QtViewer/meshviewer.cc.orig	2018-10-21 23:50:54 UTC
+++ src/OpenMesh/Apps/QtViewer/meshviewer.cc
@@ -63,6 +63,9 @@
 #else
 #include <GL/glut.h>
 #endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
 #include "MeshViewerWidget.hh"
 
