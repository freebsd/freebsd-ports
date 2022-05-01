--- dart/gui/glut/LoadGlut.hpp.orig	2021-11-04 20:43:53 UTC
+++ dart/gui/glut/LoadGlut.hpp
@@ -39,6 +39,8 @@
   #include <GL/glut.h>
 #elif defined(__linux__)
   #include <GL/glut.h>
+#elif defined(__FreeBSD__)
+  #include <GL/glut.h>
 #elif defined(__APPLE__)
   #include <GLUT/glut.h>
 #else
