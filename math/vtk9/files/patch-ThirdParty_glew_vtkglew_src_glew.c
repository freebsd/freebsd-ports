--- ThirdParty/glew/vtkglew/src/glew.c.orig	2024-02-21 22:29:42 UTC
+++ ThirdParty/glew/vtkglew/src/glew.c
@@ -38,6 +38,7 @@
 
 #if defined(GLEW_OSMESA)
 #  define GLAPI extern
+#  define APIENTRY __stdcall
 #  include <GL/osmesa.h>
 #elif defined(GLEW_EGL)
 #  include <GL/eglew.h>
