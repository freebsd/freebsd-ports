--- src/OpenMesh/Apps/Decimating/decimaterviewer.cc.orig	2018-10-21 23:51:30 UTC
+++ src/OpenMesh/Apps/Decimating/decimaterviewer.cc
@@ -63,6 +63,9 @@
 #else
 #include <GL/glut.h>
 #endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#endif
 
 void usage_and_exit(int xcode);
 
