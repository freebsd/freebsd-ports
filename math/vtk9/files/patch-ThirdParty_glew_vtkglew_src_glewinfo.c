--- ThirdParty/glew/vtkglew/src/glewinfo.c.orig	2024-02-21 22:29:54 UTC
+++ ThirdParty/glew/vtkglew/src/glewinfo.c
@@ -38,6 +38,7 @@
 #include <GL/eglew.h>
 #elif defined(GLEW_OSMESA)
 #define GLAPI extern
+#define APIENTRY __stdcall
 #include <GL/osmesa.h>
 #elif defined(_WIN32)
 #include <GL/wglew.h>
