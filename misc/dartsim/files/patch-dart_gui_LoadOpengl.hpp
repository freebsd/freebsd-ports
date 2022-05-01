--- dart/gui/LoadOpengl.hpp.orig	2021-11-04 20:43:53 UTC
+++ dart/gui/LoadOpengl.hpp
@@ -46,6 +46,9 @@
 #elif defined(__linux__)
   #include <GL/gl.h>
   #include <GL/glu.h>
+#elif defined(__FreeBSD__)
+  #include <GL/gl.h>
+  #include <GL/glu.h>
 #elif defined(__APPLE__)
   #include <OpenGL/gl.h>
   #include <OpenGL/glu.h>
