--- dart/gui/glut/LoadGlut.hpp.orig	2021-07-15 08:12:45 UTC
+++ dart/gui/glut/LoadGlut.hpp
@@ -38,6 +38,8 @@
 #  include <GL/glut.h>
 #elif defined(__linux__)
 #  include <GL/glut.h>
+#elif defined(__FreeBSD__)
+#  include <GL/glut.h>
 #elif defined(__APPLE__)
 #  include <GLUT/glut.h>
 #else
