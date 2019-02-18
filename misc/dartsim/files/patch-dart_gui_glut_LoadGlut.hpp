--- dart/gui/glut/LoadGlut.hpp.orig	2019-02-18 02:40:12 UTC
+++ dart/gui/glut/LoadGlut.hpp
@@ -38,6 +38,8 @@
   #include <GL/glut.h>
 #elif defined(__linux__)
   #include <GL/glut.h>
+#elif defined(__FreeBSD__)
+  #include <GL/glut.h>
 #elif defined(__APPLE__)
   #include <GLUT/glut.h>
 #else
